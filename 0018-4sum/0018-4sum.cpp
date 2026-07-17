class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        // BRUTE
        // set<vector<int>>s;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             int sum=0;
        //             for(int l=k+1;l<nums.size();l++){
        //                 if(nums[i]+nums[j]+nums[k]+nums[l]==target){
        //                     vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
        //                     sort(temp.begin(),temp.end());
        //                     s.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>ans(s.begin(),s.end());
        // return ans;
        //BETTER
        // set<vector<int>>s;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         set<int>hashset;
        //         for(int k=j+1;k<n;k++){
        //         int fourth=target-(nums[i]+nums[j]+nums[k]);
        //         if(hashset.find(fourth)!=hashset.end()){
        //             vector<int>temp={nums[i],nums[j],nums[k],fourth};
        //             sort(temp.begin(),temp.end());
        //             s.insert(temp);
        //         }
        //         hashset.insert(nums[k]);
        //     }
        //     }
        // }
        // vector<vector<int>>ans(s.begin(),s.end());
        // return ans;
        //OPTIMAL
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum<target) k++;
                    else if(sum>target) l--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l&&nums[k]==nums[k-1]) k++;
                        while(k<l&&nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};