class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newCol, int org){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]==newCol || image[i][j]!=org) return;
        image[i][j]=newCol;
        dfs(image,i-1,j,newCol,org);
        dfs(image,i+1,j,newCol,org);
        dfs(image,i,j-1,newCol,org);
        dfs(image,i,j+1,newCol,org);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};