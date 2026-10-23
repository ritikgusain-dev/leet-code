struct node{
    node* links[26];
    bool flag=false;
    node(){
        for(int i=0;i<26;i++) links[i]=nullptr;
    }
};
class Trie {
    private:
    node * root= new node();
public:
    Trie() {
       
    }
    
    void insert(string word) {
        node * tempRoot = root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(tempRoot->links[idx]==nullptr){
                tempRoot->links[idx]=new node();
            }
            if(i==word.size()-1) tempRoot->links[idx]->flag=true;
            tempRoot=tempRoot->links[idx];
        }
    }
    
    bool search(string word) {
        node* tempRoot = root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(tempRoot->links[idx]==nullptr) return false;
            if(i==word.size()-1){
                if(tempRoot->links[idx]->flag==true) return true;
                else return false;
            }
            tempRoot=tempRoot->links[idx];
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        node* tempRoot= root;
        for(int i=0;i<prefix.size();i++){
            int idx= prefix[i]-'a';
            if(tempRoot->links[idx]==nullptr) return false;
            tempRoot=tempRoot->links[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */