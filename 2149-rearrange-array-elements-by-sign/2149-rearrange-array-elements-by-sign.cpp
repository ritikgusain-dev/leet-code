class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        //BRUTE
        // vector<int>t1;
        // vector<int>t2;
        // for(int i=0;i<n;i++){
        //     if(nums[i]>0){
        //         t1.push_back(nums[i]);
        //     }
        //     else t2.push_back(nums[i]) ;
        // }
        // for(int i=0;i<n/2;i++){
        //     nums[i*2]=t1[i];
        //     nums[i*2+1]=t2[i];
        // }
        // return nums;
        //BETTER
        vector<int>ans(n,0);
        int pos=0;
        int neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                pos+=2;
            }
            else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};