class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int r=1e8;
        int res=r;
        while(l<=r) {
            int mid=(l+r)/2;
            int cnt=0;
            for(auto i:quantities) {
                cnt+=i/mid;
                if(i%mid!=0) {
                    cnt++;
                }
            }
            if(cnt>n) {
                l=mid+1;
            } else {
                res=mid;
                r=mid-1;
            }
        }
        return res;
    }
};