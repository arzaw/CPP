#include <bits/stdc++.h>
using namespace std;

int kthSmallest_sorting(int arr[], int n, int k) {
    // Sort the array
    sort(arr, arr + n);
    
    // Return the k-th smallest element
    return arr[k - 1];
}

int kthSmallest_heap(int arr[], int n, int k) {
    // Create a max heap of size k
    priority_queue<int> maxHeap;
    
    // Insert first k elements into the max heap
    for (int i = 0; i < k; i++) {
        maxHeap.push(arr[i]);
    }
    
    // Process the remaining elements
    while (maxHeap.size()>k)
    {
        maxHeap.pop();
        /* code */
    }
    
    // The root of the max heap is the k-th smallest element
    return maxHeap.top();
}

int kthSmallest_Max_Element_Array(vector<int> &arr, int n, int k) {
    int maxElement;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    int freq[maxElement+1]={0};

    for(int i = 0; i < n ; i++){
        freq[arr[i]]++;
    }

    int count=0;
    
    for(int i=0; i<=maxElement; i++){
        if(freq[i] != 0){
            count+=freq[i];
            if(count >= k){
                return i;
            }
        }
    }

    return -1;

}
