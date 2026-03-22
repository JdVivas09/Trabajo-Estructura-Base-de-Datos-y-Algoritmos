#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct Node{

    string data;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* n){

    if (n == nullptr){
        return 0;
    }

    return n -> height;
}

int getBalance(Node* n){

    if (n == nullptr){
        return 0;
    }

    return getHeight(n -> left) - getHeight(n -> right);
}

Node* newNode(string data){

    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

void updateHeight(Node* n){

    if (n){

        n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    }
}

Node* rotateRight(Node* y){

    Node* x = y->left;
    Node* Temp = x->right;
    x->right = y;
    y->left = Temp;

    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* rotateLeft(Node* x){

    Node* y = x->right;
    Node* Temp = y->left;
    y->left = x;
    x->right = Temp;

    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* insert(Node* node, const string& data){

    if (!node){

        return newNode(data);
    }

    if (data < node->data){

        node->left  = insert(node->left,  data);
    }

    else if (data > node->data){

        node->right = insert(node->right, data);
    }

    else{

        return node;
    }

    updateHeight(node);
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data){

        return rotateRight(node);
    }

    if (balance < -1 && data > node->right->data){

        return rotateLeft(node);
    }

    if (balance > 1 && data > node->left->data){

        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && data < node->right->data){

        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorder(Node* root, vector<string>& result){

    if (!root){

        return;
    }
    
    inorder(root->left,  result);
    result.push_back(root->data);
    inorder(root->right, result);
}
void deleteTree(Node* root){

    if (!root)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void avlSort(vector<string>& arr){

    Node* root = nullptr;

    for (const auto& word : arr){

        root = insert(root, word);
    }

    vector<string> result;
    inorder(root, result);
    arr = result;
    deleteTree(root);
}