class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        //first find the index jahan se hum permutation banana start kar sakte hain, since we need to find next permutation, humko vo index dhundna jaha se right ki taraf us index par rakhe element se bada number ho taaki next permutation mil sake
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        //If no pivot exists, the array is already the largest possible permutation (completely descending). Therefore, the next permutation is the smallest permutation, which is obtained by reversing (sorting in ascending order).
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        // humko just next permutation chiye so, we will find the number which is greater than the index par rkha hua element but smaller than all the elements present on left, as soon as we find it, we swap them, 
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        //now reverse the array from ind+1 to last index to attain the smallest number
        reverse(nums.begin()+ind+1,nums.end());
    }
};