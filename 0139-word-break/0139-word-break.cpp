class node{
    public:
    node*children[26];
    bool eow = false;
    node(){
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
};
class trie{
    node*root=new node();
    public:
    void insert(string s){
        node*temp = root;
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            if(temp->children[idx]==nullptr) temp->children[idx]=new node();
            if(i==s.size()-1) temp->children[idx]->eow = true;
            temp=temp->children[idx];
        }
    }
    bool search(string s){
        node * temp=root;
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            if(temp->children[idx]==nullptr) return false;
            if(i==s.size()-1 && temp->children[idx]->eow==false) return false;
            temp=temp->children[idx];
        }
        return true;
    }
};
class Solution {
public:
    bool fun(string& s, trie& obj, int start, vector<int>& dp) {
        if(start == s.size()) return true;

        if(dp[start] != -1) return dp[start];

        for(int i = start + 1; i <= s.size(); i++) {
            string part = s.substr(start, i - start);

            if(obj.search(part) && fun(s, obj, i, dp))
                return dp[start] = true;
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        trie obj;

        for(string word : wordDict)
            obj.insert(word);

        vector<int> dp(s.size(), -1);

        return fun(s, obj, 0, dp);
    }
};