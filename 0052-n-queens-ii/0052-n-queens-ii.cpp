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
    void solve(vector<string>&board, int &c,int row, int n){
        if(row==n){
            c++;
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j]='Q';
                solve(board,c,row+1,n);
                board[row][j]='.';
            }
        }
        return ;
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int c=0;
        solve(board,c,0,n);
        return c;
    }
};