class Solution {
public:
    bool canPlace(vector<int>&position,int minDis,int total){
        int totalPlaced=1,lastPlaced=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-lastPlaced>=minDis){
                totalPlaced++;
                lastPlaced=position[i];
            }
            if(totalPlaced==total) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=0,high=position[position.size()-1]-position[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canPlace(position,mid,m)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};