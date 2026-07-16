class Solution {
public:
    void sortColors(vector<int>& nums) {
        //BETTER
        // int c1=0,c2=0,c3=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0) c1++;
        //     else if(nums[i]==1) c2++;
        //     else c3++;
        // }
        // for(int i=0;i<c1;i++){
        //     nums[i]=0;
        // }
        // for(int i=c1;i<c1+c2;i++){
        //     nums[i]=1;
        // }
        // for(int i=c1+c2;i<nums.size();i++){
        //     nums[i]=2;
        // }
        //OPTIMAL(DUTCH NATIONAL FLAG)
        int low=0, mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1) mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
    }
};