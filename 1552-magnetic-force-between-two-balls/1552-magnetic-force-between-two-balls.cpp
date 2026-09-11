//we need to put ALL the balls, the distance between all the balls will vary, we need to find  the min distance of every possible arrangement each time and that minimum distance must be maximum possible distance of any arangement
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
        int low=0; //minimum possible distance between 2 balls
        int high=position[position.size()-1]-position[0]; //maximum possible distance between 2 balls
        while(low<=high){
            //mid will be randomly picking distances between low and high and checks whether the distance is possible to utilise all the balls within the size and 
            int mid=low+(high-low)/2;
            if(canPlace(position,mid,m)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};