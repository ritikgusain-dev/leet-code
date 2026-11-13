class Solution {
public:
    int hammingWeight(int n) {
        // NORMAL O(32) // find bit at ith position and check if it's 1
        int c=0;
        // for(int i = 31 ;i>=0;i--){
        //     if((n>>i)&1 == 1) c++;
        // }
        // unset the right most set bit and repeat until the number becomes 0;
        // while(n!=0){
        //     n=n&n-1;
        //     c++;
        // }
        // NORMALLY KEEP ON DIVIDING THE NUMBER BY 2 UNTIL THE NUMBER  BECOMES 0, AND KEEP ON CHECKING THE REMAINDER IT IT'S 1
        while(n!=0){
            if(n%2!=0) c++;
            n=n/2;
        }
        return c;
    }
};