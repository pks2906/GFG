//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> solutions;
        vector<int> board(n, -1);
        solveNQueen(solutions, board, 0);
        return solutions;
    }

    void solveNQueen(vector<vector<int>>& solutions, vector<int>& board, int row) {
        int n = board.size();
        if (row == n) {
            vector<int> solution;
            for (int i = 0; i < n; i++) {
                solution.push_back(board[i] + 1);
            }
            solutions.push_back(solution);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row] = col;
                solveNQueen(solutions, board, row + 1);
                board[row] = -1;
            }
        }
    }

    bool isSafe(vector<int>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
                return false;
            }
        }
        return true;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends