class Solution {
public:
    int hammingWeight(int n) {
        // NORMAL O(32) // find bit at ith position and check if it's 1
        int c=0;
        // for(int i = 31 ;i>=0;i--){
        //     if((n>>i)&1 == 1) c++;
        // }
        // unset the right most set bit and repeat until the number becomes 0;
        while(n!=0){
            n=n&n-1;
            c++;
        }
        return c;
    }
};