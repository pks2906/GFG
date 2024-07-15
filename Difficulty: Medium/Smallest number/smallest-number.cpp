//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        if (9 * d < s) {
            return "-1";
        }
        if (s > 9) {
            return smallestNumber(s - 9, d - 1) + "9";
        }
        if (d == 1){
            return to_string(s);
        }
        if (s > 1) {
            return smallestNumber(1, d - 1) + to_string(s - 1);
        }
        
        return smallestNumber(1, d - 1) + "0";
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends