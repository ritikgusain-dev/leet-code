class Solution {
public:
    int maxx(vector<int>& a){
        int maz=-1;
        for(int i=0;i<a.size();i++){
            if(a[i]>=maz) maz=a[i];
        }
        return maz;
    }
    bool canDistribute(int n,int random,vector<int>&a){
        for(int i=0;i<a.size();i++){
            if(a[i]%random!=0) n-=((a[i]/random)+1);
            else n-=(a[i]/random);
            if(n<0) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
      int low=1,high=maxx(quantities);  
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canDistribute(n,mid,quantities)) high=mid-1;
            else low = mid+1;
        }
        return low;
    }
};