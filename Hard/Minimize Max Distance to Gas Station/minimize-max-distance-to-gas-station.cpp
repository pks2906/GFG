//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        sort(stations.begin(), stations.end());
        
        // Function to check if it's possible to ensure max distance d with k or fewer additional stations
        auto isPossible = [&](double d) {
            int requiredStations = 0;
            for (int i = 1; i < stations.size(); i++) {
                double distance = stations[i] - stations[i - 1];
                requiredStations += ceil(distance / d) - 1;
            }
            return requiredStations <= k;
        };

        double left = 0, right = stations.back() - stations.front();
        double result = right;

        // Binary search
        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            if (isPossible(mid)) {
                result = mid;
                right = mid;
            } else {
                left = mid;
            }
        }

        return round(result * 100) / 100.0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends