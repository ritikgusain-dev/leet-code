class Solution {
public:
    int fun(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else return 1000;
    }
    int romanToInt(string s) {
        int sum = 0;
        for(int i=0;i<s.size()-1;i++){
            int m = fun(s[i]);
            int n = fun(s[i+1]);
            if(m<n) sum-=m;
            else sum+=m;
        }
        int x = fun(s[s.size()-1]);
        sum+=x;
        return sum;
    }
};