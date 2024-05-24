//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Create a set to store the elements of the first array
        unordered_set<int> s(a, a + n);
        
        // Initialize the count of common elements
        int count = 0;
        
        // Iterate through the second array
        for (int i = 0; i < m; i++) {
            // If the element is in the set, increment the count and remove the element from the set
            if (s.find(b[i]) != s.end()) {
                count++;
                s.erase(b[i]);
            }
        }
        
        // Return the count of common elements
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends