class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx=INT_MIN;
        //BRUTE
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int pro=1;
        //     for(int j=i;j<n;j++){
        //         pro*=nums[j];
        //         maxx=max(pro,maxx);
        //     }
        // }
        // return maxx;
        //OPTIMAL
        int pre=1;
        int suf=1;
        for(int i=0;i<nums.size();i++){
            if(pre==0) pre=1;
            if(suf==0) suf=1;
            pre*=nums[i];
            suf*=nums[n-i-1];
            maxx=max(maxx,max(pre,suf));
        }
        return maxx;
    }
};