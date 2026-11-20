class Solution {
public:
    void dfs(vector<vector<int>>&isConnected , int node , int n , vector<int>&visited){
        visited[node] = 1;
        for(int i = 0;i<n;i++){
            if(!visited[i] && isConnected[node][i]==1) dfs(isConnected,i,n,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        int c = 0;
        vector<int>visited(n,0);
        for(int i = 0 ;i<n;i++){
            if(!visited[i]){
                c++;
                dfs(isConnected,i,n,visited);
            }
        }
        return c;
    }
};