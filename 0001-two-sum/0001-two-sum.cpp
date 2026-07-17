class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>ans;
    //    for(int i=0;i<nums.size();i++){
    //     for(int j=i+1;j<nums.size();j++){
    //         if(nums[i]+nums[j]==target){
    //             ans.push_back(i);
    //             ans.push_back(j);
    //             break;
    //         }
    //     }
    //    } 
    //BETTER
    // unordered_map<int,int>mp;
    // for(int i=0;i<nums.size();i++){
    //     if(mp.find(target-nums[i])==mp.end()){
    //         mp[nums[i]]=i;
    //     }
    //     else{
    //         ans.push_back(i);
    //         ans.push_back(mp[target-nums[i]]);
    //         break;
    //     }
    // }
    //OPTIMAL
    vector<pair<int,int>>v;
    for(int i=0;i<nums.size();i++){
        v.push_back({nums[i],i});
    }
    sort(v.begin(),v.end());
    int i=0;
    int j=nums.size()-1;
    while(i<j){
        if(v[i].first+v[j].first==target){
            ans.push_back(v[i].second);
            ans.push_back(v[j].second);
            break;
        }
        else if(v[i].first+v[j].first>target) j--;
        else i++;
    }
       return ans;
    }
};