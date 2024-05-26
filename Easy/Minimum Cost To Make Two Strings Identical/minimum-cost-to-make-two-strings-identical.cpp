//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int findMinCost(string x, string y, int costX, int costY) {
        int m = x.length();
        int n = y.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

      
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (x[i-1] == y[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }

        
        int lenLCS = dp[m][n];

        
        return costX * (m - lenLCS) + costY * (n - lenLCS);
    }
};

  // solved by Pratik


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends