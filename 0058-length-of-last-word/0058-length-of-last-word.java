class Solution {
    public int lengthOfLastWord(String s) {
        s=s.trim();
        int i=s.length()-1;
        int c=0;
        while(i>=0&&s.charAt(i)!=32){
            c++;
            i--;
        }
        return c;
    }
}