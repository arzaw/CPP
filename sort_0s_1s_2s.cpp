#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int>& arr) {
    // code here
    int zeros=0, ones=0, twos=0;
    for(int i=0; i < arr.size(); i++){
        switch(arr[i]){
            case 0:
                zeros++;
                break;
            case 1:
                ones++;
                break;
            case 2:
                twos++;
                break;
        }
    }
    int k=0;
    while(zeros){
        arr[k++] = 0;
        zeros--;
    }
    
    while(ones){
        arr[k++] = 1;
        ones--;
    }
    
    while(twos){
        arr[k++] = 2;
        twos--;
    }
    
}

// The issues with this approach are:

// It would not work if 0s and 1s represent keys of objects.
// Not stable
// Requires two traversals of the array

// Dutch National Flag Algorithm – One Pass – O(n) Time and O(1) Space

// C++ program to sort an array of 0s, 1s and 2s 
// using Dutch National Flag Algorithm

// Function to sort an array of 0s, 1s and 2s
void sort012(vector<int> &arr) {
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;
    int mid = 0;

    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        if (arr[mid] == 0)
            swap(arr[lo++], arr[mid++]);
        else if (arr[mid] == 1)
            mid++;
        else
            swap(arr[mid], arr[hi--]);
    }
}

int main() {
    vector<int> arr = { 0, 1, 2, 0, 1, 2 };
    int n = arr.size();

    sort012(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
