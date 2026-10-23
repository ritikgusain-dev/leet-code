class node{
    public:
    node*children[26];
    int startIdx = -1;
    node(){
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
};
class trie{
    private:
    node*root=new node();
    public:
    void insert(string s){
       node*temp;
       for(int i=0;i<s.size();i++){
        temp=root; // for storing every possible substring of haystack so that even if the needle starts from the middle of haystack , trie can determine the occurance of it, temp is going back again to root each time for every iteration of i OR for storing every possible substring of haystack aur temp->children[idx] ki value agar -1 hai it means vo substring pehli bar dikh rahi hai , since starting of every substring is denoted by i and i se haystack ki length tak jaane ka kaam already j kar rha  hai , our i will be storing the starting of substring 
        for(int j=i;j<s.size();j++){
        int idx=s[j]-'a';
        if(temp->children[idx]==nullptr){
            temp->children[idx]=new node();
        }
        temp=temp->children[idx];
        if(temp->startIdx==-1) temp->startIdx=i;
        }
       } 
    }
    int search(string s){
        node*temp=root;
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            if(temp->children[idx]==nullptr) return -1;
            temp=temp->children[idx];
        }
        return temp->startIdx;
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        // BRUTE FORCE AKA NAIVE ALGORITHM OF STRING MATCHING
        // int n = haystack.size();
        // int m = needle.size();

        // for (int i = 0; i <= n - m; i++) {
        //     int j = 0;

        //     while (j < m && haystack[i + j] == needle[j])
        //         j++;

        //     if (j == m)
        //         return i;
        // }

        // return -1;
        //USING TRIE
        trie obj;
        obj.insert(haystack);
        int ans=obj.search(needle);
        return ans;
    }
};
