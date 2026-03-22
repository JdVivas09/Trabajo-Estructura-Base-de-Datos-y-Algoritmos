#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
void maxHeap(vector<string> &vec, int n, int i){

    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && vec[left] > vec[largest]){
        
        largest = left;
    }

    if(right < n && vec[right] > vec[largest]){

        largest = right;
    }

    if(largest != i){

        swap(vec[i], vec[largest]);
        maxHeap(vec, n, largest);
    }
}

void heapSort(vector<string> &vec){

    int n = vec.size();

    for(int i = n/2 - 1; i >= 0; i--){
        
        maxHeap(vec, n, i);
    }

    for(int i = n - 1; i > 0; i--){

        swap(vec[0], vec[i]);
        maxHeap(vec, i, 0);
    }
}