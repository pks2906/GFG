//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        if (sum < d || (sum + d) % 2 != 0)
            return 0;
        sum = (sum + d) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i - 1])
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]) % 1000000007;
            }
        }
        return dp[n][sum];
    }
};







//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends