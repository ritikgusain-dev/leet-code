class Solution {
public:
    int hammingWeight(int n) {
        // NORMAL 
        int c=0;
        for(int i = 31 ;i>=0;i--){
            if((n>>i)&1 == 1) c++;
        }
        return c;
    }
};