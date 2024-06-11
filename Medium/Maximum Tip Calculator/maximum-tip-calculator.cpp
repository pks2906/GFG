//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends



class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<int, int>> diffs;
        for (int i = 0; i < n; i++) {
            diffs.push_back({arr[i] - brr[i], i});
        }

        
        sort(diffs.begin(), diffs.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return abs(a.first) > abs(b.first);
        });

        long long totalTip = 0;
        int countA = 0, countB = 0;

        for (auto &diff : diffs) {
            int index = diff.second;
            if (diff.first > 0) { 
                if (countA < x) {
                    totalTip += arr[index];
                    countA++;
                } else {
                    totalTip += brr[index];
                    countB++;
                }
            } else { 
                if (countB < y) {
                    totalTip += brr[index];
                    countB++;
                } else {
                    totalTip += arr[index];
                    countA++;
                }
            }
        }

        return totalTip;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends