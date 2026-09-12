//we need to put ALL the balls, the distance between all the balls will vary, we need to find  the min distance of every possible arrangement each time and that minimum distance must be maximum possible distance of that one answer arangement, in this answer arrangement , the minimum distance between 2 balls is the answer
class Solution {
public:
    // we used binary search because after we failed to put all the balls in a certain assumed distance , we do not want to calculate for further increased distances since we have already failed in shorter distance
    bool canPlace(vector<int>&position,int minDis,int total){
        //we put 1 ball by ourself at position[0], stil we need to put total-1 balls
        int totalPlaced=1,lastPlaced=position[0];
        //0th index is already occupied, start from 1 index
        for(int i=1;i<position.size();i++){
            //if the difference between current element and the lastPlaced element is greater than or equal than the distance which mid is representing, then we can place our next ball here and update lastPlaced to this ball
            if(position[i]-lastPlaced>=minDis){
                totalPlaced++;
                lastPlaced=position[i];
            }
            if(totalPlaced==total) return true;
        }
        //if we are unable to put all the balls (bina true return kiye loop ke bahar agaye) , it means that mid ne jo distance assume kiya tha, uske hisab se hum saari balls nahi rakh paaye and that distance is not possible to arrange all the balls
        // now high will be mid-1 and new mid is again calculated untill low<=high.
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1; //minimum possible distance between 2 balls
        int high=position[position.size()-1]-position[0]; //maximum possible distance between 2 balls
        while(low<=high){
            //mid will be randomly picking distances between low and high and checks whether the distance is possible to utilise all the balls within the size of the given vector
            int mid=low+(high-low)/2;
            //changing the range(low-high) each time (depeding upon the canPlace) and moving closer to the answer
            if(canPlace(position,mid,m)) low=mid+1;
            else high=mid-1;
        }
        // AT THE END , HIGH WILL BE THE BOUNDARY JISKE LEFT M SAARI POSSIBLE DISTANCES HONGI AND RIGHT M SAAARI IMPOSSIBLE DISTANCES
        return high;
    }
};