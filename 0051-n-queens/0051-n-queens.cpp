class Solution {
public:
    bool isSafe(vector<string>&board, int row, int col, int n){
        //vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }
        //horizontal
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q') return false;
        }
        //upper left diagonal
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        //lower left diagonal
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }

        return true;
    }
    void solve(vector<string>&board,int row,vector<vector<string>>&ans,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j]='Q';
                solve(board,row+1,ans,n);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        solve(board,0,ans,n);
        return ans;
    }
};