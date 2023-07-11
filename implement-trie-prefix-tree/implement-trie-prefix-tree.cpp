class Trie {
public:
    unordered_map<string,int> mp;
    Trie() {
        mp.clear();
    }
    
    void insert(string word) {
        mp[word]++;
    }
    
    bool search(string word) {
        auto it = mp.find(word);
        return !(it==mp.end());
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        for(auto it : mp){
            int m = it.first.size();
            if(m >= n){
                if((it.first).substr(0,n)== prefix) return true; 
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */