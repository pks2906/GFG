//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    vector<int> bracketNumbers(string str) {
        vector<int> result;
        stack<int> stk;
        int counter = 1;

        for (char ch : str) {
            if (ch == '(') {
                stk.push(counter);
                result.push_back(counter);
                counter++;
            } else if (ch == ')') {
                if (!stk.empty()) {
                    int top = stk.top();
                    stk.pop();
                    result.push_back(top);
                }
            }
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends