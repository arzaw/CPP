//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        int a_max=a[0];
        int b_max=b[0];
        
        for(int i=1; i<a.size(); i++){
            if(a_max<a[i])
                a_max = a[i];
        }
        
        for(int i=1; i<b.size(); i++){
            if(b_max<b[i])
                b_max = b[i];
        }
        
        int size, r=0;
        
        if(a_max > b_max)
            size = a_max+1;
        else
            size = b_max+1;
        int res[size]={0};
        
        for(int i=0; i<a.size(); i++){
            res[a[i]]++;
        }
        
        for(int i=0; i<b.size(); i++){
            res[b[i]]++;
        }
        
        for(int i=0; i < size ; i++){
            //cout<<res[i]<<endl;
            if(res[i]>0)
                r++;
        }
        
        return r;
    }
};


// Another approach using one loop

// C++ program to find union of two sorted arrays using 
// merge step of merge sort

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int>& a,  vector<int>& b) {
    vector<int> res; 
    int n = a.size();
    int m = b.size();
  
    // This is similar to merge of merge sort
    int i = 0, j = 0;    
    while(i < n && j < m) {
      
        // Skip duplicate elements in the first array
        if(i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
      
      	// Skip duplicate elements in the second array
      	if(j > 0 && b[j - 1] == b[j]) {
          	j++;
          	continue;
        }
      	
      	// select and add the smaller element and move
        if(a[i] < b[j]) {
          	res.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j]) {
          	res.push_back(b[j]);
            j++;
        }
      
        // If equal, then add to result and move both 
        else {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
  	
  	// Add the remaining elements of a[]
  	while (i < n) {
      	
      	// Skip duplicate elements in the first array
      	if(i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
      	res.push_back(a[i]);
      	i++;
    }
  
  	// Add the remaining elements of b[]
  	while (j < m) {
      
      	// Skip duplicate elements in the second array
      	if(j > 0 && b[j - 1] == b[j]) {
            j++;
            continue;
        }
      	res.push_back(b[j]);
      	j++;
    }
    return res; 
}

int main() {
  
    vector<int> a = {1, 1, 2, 2, 2, 4};
    vector<int> b = {2, 2, 4, 4};
  
    vector<int> res = findUnion(a, b);
    for (int x : res) {
        cout << x << " ";
    }
}