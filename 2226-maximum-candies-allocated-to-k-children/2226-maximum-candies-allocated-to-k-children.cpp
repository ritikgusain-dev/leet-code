class Solution {
public:
    bool canDistribute(vector<int>&a,int val,long long k){
        long long c=0;
        for(int i=0;i<a.size();i++){
            c+=a[i]/val;
            if(c>=k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1,high=*max_element(candies.begin(),candies.end());
        int tempHigh=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canDistribute(candies,mid,k)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};