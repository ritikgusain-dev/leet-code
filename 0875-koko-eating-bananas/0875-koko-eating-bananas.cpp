class Solution {
public:
    bool canEat(vector<int>&a,int time, int val){
        int c=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<=val) c+=1;
            else {
                if(a[i]%val==0)
                c+=(a[i]/val);
                else 
                c+=(a[i]/val)+1;
            }
            if(c>time) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = low + ( high - low ) / 2;
            if(canEat(piles,h,mid)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};