class Solution {
public:
    bool isSafe(vector<string>&board,int row,int col,int n){
        //horizontal
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q') return false;
        }
        //vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }
        //upper left diagonal
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        //upper right diagonal
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
        }
    void solve(vector<string>&board, vector<vector<string>>&ans,int row, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j]='Q';
                solve(board,ans,row+1,n);
                board[row][j]='.';
            }
        }
        return ;
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        solve(board,ans,0,n);
        return ans.size();
    }
};