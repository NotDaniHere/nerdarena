// C++ program to find maximum Subarray Sum in Circular
// subarray by considering all possbile subarrays

#include <bits/stdc++.h>
using namespace std;
ifstream fin("colier.in");
ofstream fout("colier.out"); 


int circularSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int res = arr[0];
    
    // Subarray that starts with index i
    for(int i = 0; i < n; i++) {
        int currSum = 0;
        
        // Considering all possible endpoints of the 
        // Subarray that begins with index i
        for(int j = 0; j < n; j++) {
            
            // Circular index
            int idx = (i + j) % n;
            currSum = currSum + arr[idx];            
            res = max(res, currSum);
        }
    }
    
    return res;
}

int main() {

    int a; fin >> a;
    vector<int> arr(a);
    for(int i = 0; i < a; i++) {
        fin >> arr[i];
    }
    fout << circularSubarraySum(arr);
}
