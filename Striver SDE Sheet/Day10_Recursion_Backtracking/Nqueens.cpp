// https://leetcode.com/problems/n-queens/description/
// https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/

class Solution {
public:
    void func(int col, vector<string> &board, int n, vector<int> &leftRow, vector<int> &UpperDiagonal, vector<int> &LowerDiagonal, vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(leftRow[row]==0 && UpperDiagonal[n-1+col-row]==0 && LowerDiagonal[row+col]==0){
                board[row][col]='Q';
                leftRow[row]= 1; 
                UpperDiagonal[n-1+col-row]= 1; 
                LowerDiagonal[row+col]= 1;
                func(col+1, board, n, leftRow, UpperDiagonal, LowerDiagonal, ans);
                board[row][col]='.';
                leftRow[row]= 0; 
                UpperDiagonal[n-1+col-row]= 0; 
                LowerDiagonal[row+col]= 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i]=s;
        }
        vector<int> leftRow(n,0);
        vector<int> UpperDiagonal(2*n - 1,0);
        vector<int> LowerDiagonal(2*n - 1, 0);
        func(0, board, n, leftRow, UpperDiagonal, LowerDiagonal, ans);
        return ans;
    }
};
