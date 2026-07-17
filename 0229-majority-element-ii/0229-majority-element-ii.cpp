class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //BETTER
        // unordered_map<int,int>mp;
        // vector<int>ans;
        // double mm=(nums.size()/3)+1;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        //     if(mp[nums[i]]==mm) ans.push_back(nums[i]);
        // }
        // return ans;
        //OPTIMAL
        vector<int>ans;
        int c1=0,c2=0,el1,el2;
        for(int i=0;i<nums.size();i++){
            if(c1==0&&nums[i]!=el2){
                el1=nums[i];
                c1=1;
            }
            else if(c2==0&&nums[i]!=el1){
                el2=nums[i];
                c2=1;
            }
            else if(nums[i]==el1) c1++;
            else if(nums[i]==el2) c2++;
            else{
                c1--;
                c2--;
            }
        }
        double mm=(nums.size()/3)+1;
        int c3=0,c4=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1) c3++;
            if(nums[i]==el2) c4++;
        }
        if(c3>=mm) ans.push_back(el1);
        if(c4>=mm) ans.push_back(el2);
        return ans;
    }
};