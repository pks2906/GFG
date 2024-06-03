//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        const int MOD = 1e9 + 7;
        if (n == 1) return 0;

        vector<long long> dp0(n + 1, 0), dp1(n + 1, 0);
        dp0[1] = 1;
        dp1[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp0[i] = (dp0[i - 1] + dp1[i - 1]) % MOD;
            dp1[i] = dp0[i - 1];
        }

        long long total = 1; 
        for (int i = 0; i < n; ++i) {
            total = (total * 2) % MOD; 
        }

        long long noConsecutiveOnes = (dp0[n] + dp1[n]) % MOD;
        return (total - noConsecutiveOnes + MOD) % MOD; 
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends