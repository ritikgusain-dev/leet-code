class Solution {
public:
    vector<int>printRow(int n){
        vector<int>ans;
        long long a=1;
        ans.push_back(a);
        for(int i=0;i<n;i++){
            a=a*(n-i);
            a=a/(i+1);
            ans.push_back(a);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(printRow(i));
        }
        return ans;
    }
};