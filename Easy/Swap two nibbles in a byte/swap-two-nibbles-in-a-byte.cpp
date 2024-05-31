//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int swapNibbles(int n) {
        
        int leftShifted = (n & 0x0F) << 4;
        
        int rightShifted = (n & 0xF0) >> 4;
        
        return leftShifted | rightShifted;
    }
};

//solved by Pratik


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends