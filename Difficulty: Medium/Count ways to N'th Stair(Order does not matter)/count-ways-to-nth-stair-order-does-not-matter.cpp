//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int nthStair(int n) {
        // Initialize result
        int result = 0;
        
        // Count number of 2s
        for (int i = 0; i <= n/2; i++) {
            result++;
        }
        
        return result;
    }
};





//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends