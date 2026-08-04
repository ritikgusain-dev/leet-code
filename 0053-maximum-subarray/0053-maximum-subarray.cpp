class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0;
        int maxx=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     s=0;
        //     for(int j=i;j<nums.size();j++){
        //         s+=nums[j];
        //         maxx=max(maxx,s);
        //     }
        // }
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s>maxx)
            {
                maxx=s;
            }
            if(s<0) s=0;
        }
        return maxx;
    }
};