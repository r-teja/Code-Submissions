class Trie {
public:
    struct TrieNode{
        struct TrieNode* arr[26];
        bool end;
    };
    struct TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->arr[word[i]-'a']==NULL){
                temp->arr[word[i]-'a']=new TrieNode();
            }
            temp=temp->arr[word[i]-'a'];
        }
        temp->end=true;
    }
    
    bool search(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->arr[word[i]-'a']==NULL){
                return false;
            }
            temp=temp->arr[word[i]-'a'];
        }
        return temp->end==true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp=root;
        for(int i=0;i<prefix.length();i++){
            if(temp->arr[prefix[i]-'a']==NULL){
                return false;
            }
            temp=temp->arr[prefix[i]-'a'];
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
