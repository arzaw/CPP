// C++ program to Move all negative numbers
// to beginning and positive to end
#include <bits/stdc++.h>
using namespace std;

vector<int> move(vector<int> &arr) {
    int l=0;
    int h=arr.size()-1;
    
    while(l<h){
        if(arr[l]>0){
            while(arr[h]>0){
                h--;
            }
            swap(arr[l++],arr[h--]);
        } else {
            l++;
        }
    }
    
    return arr;
}

int main() {
    vector<int> arr = {-12, 11, 13, -5, 6, -7, 5, -3, -6};
    vector<int> ans = move(arr);
    
    for (auto num: ans) {
        cout << num << " ";
    }
    cout<<endl;

    return 0;
}
