//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    vector<int> seg;
    
    void update(int i, int j, int l, int h){
        if(j < l || j > h)
            return;
        seg[i]++;

        if(l == h)
            return;
        int mid = (l+h)>>1;
        update(2*i + 1, j, l, mid);
        update(2*i + 2, j, mid+1, h);
    }
    int query(int i, int j, int l, int h){
        if(h < j)
            return 0;
        if(l >= j)
            return seg[i];
        int mid = (l+h)>>1;
        return query(2*i+1, j, l, mid) +
        query(2*i+2, j, mid+1, h);
    }
    vector<int> constructLowerArray(vector<int> &arr) {
    
        int n = arr.size();
        seg.resize(4*n);
        vector<int> ans(n);
        vector<vector<int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({arr[i], i});
        }
        sort(temp.begin(), temp.end());
        
        for(int i=0;i<n;i++){
            ans[temp[i][1]] = query(0, temp[i][1], 0, n-1);
            update(0,temp[i][1],0,n-1);
        }
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends