//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int Maximize(int a[],int n)
    {
        // Sort the array
        sort(a, a + n);
        
        // Initialize result
        long long res = 0;
        
        // Modulo
        int mod = 1e9 + 7;
        
        // Calculate the sum
        for(int i = 0; i < n; i++)
        {
            // Use long long int for res because the answer can be very large
            res = (res + ((long long)a[i] * i) % mod) % mod;
        }
        
        // Return the result
        return res;
    }
};


//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends