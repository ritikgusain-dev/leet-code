// We need to check whether all products can be completely distributed
// among the available stores such that each store gets at most 'random'
// products, and each store receives products of only one type.
// Some stores may remain empty.
class Solution {
public:
    int maxx(vector<int>& a){
        int maz=-1;
        for(int i=0;i<a.size();i++){
            if(a[i]>=maz) maz=a[i];
        }
        return maz;
    }
    bool canDistribute(int n,int random,vector<int>&a){
        for(int i=0;i<a.size();i++){
            if(a[i]%random!=0) n-=((a[i]/random)+1);
            else n-=(a[i]/random);
            if(n<0) return false; // if saare stores m assumed number ke hisab se distribution hua and items are still remaining and stores ran out, so we have assumed too small quantity to be distributed of items to each store
        }
        // whole array is iterated(means all items are finished ) , we don't care whether each store recieved the items or not, we are only bothered about finishing the items such that each store receives the minimum possible value to finish the items .
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
      int low=1,high=maxx(quantities);  
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canDistribute(n,mid,quantities)) high=mid-1; //  if we can distribute with this randomly assumed number(mid) between low and high , then move reduce high since we want to find the minimum number jahan se aage sab possibilities (till high) valid hongi
            else low = mid+1; // if we are unable to distribute the items, then we are checking boundary ke piche since boundary ke aage to sab valid hai, increase low
        }
        return low;
    }
};