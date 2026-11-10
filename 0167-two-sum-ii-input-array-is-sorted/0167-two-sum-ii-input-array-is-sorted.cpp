class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        //BRUTE
        // for(int i=0 ;i<numbers.size();i++){
        //     for(int j=i+1;j<numbers.size();j++){
        //         if(numbers[i]+numbers[j]==target){
        //             ans.push_back(i+1);
        //             ans.push_back(j+1);
        //             return ans;
        //         }
        //     }
        // }
        // BETTER 
        int i=0,j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(numbers[i]+numbers[j] > target) j--;
            else i++;
        }
        return ans;
    }
};