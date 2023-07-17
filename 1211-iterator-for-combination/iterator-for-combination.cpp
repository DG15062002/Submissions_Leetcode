class CombinationIterator {
public:
string temp = "";set<string> st; 
    void solve(int i, int len, string str, string temp, set<string>& st) {
    if (i >= str.size()) {
        if (temp.size() == len)
            st.insert(temp);
        return;
    }
    
    temp += str[i];
    
    for (int j = i; j < str.size(); j++) {
        solve(j + 1, len, str, temp, st);
    }
}

    CombinationIterator(string characters, int combinationLength) {
        for(int i = 0; i < characters.size(); i++){
        solve(i,combinationLength,characters,temp,st);
        }
    }
    
    string next() {
        if(st.empty()) return "";
        string temp = *(st.begin());
        st.erase(st.begin());
        return temp;
    }
    
    bool hasNext() {
        return !(st.empty());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */