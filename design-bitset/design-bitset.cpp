class Bitset {
public:
string str = "";
int size1;
int ones;
int flips;
    Bitset(int size) {
        size1 = size;
        for(int i=0;i<size1;i++){
            str+='0';
        }
        ones = 0;
        flips=0;
    }
    
    void fix(int idx) {
        if(flips%2 == 0){
            //means i am thinking that '1' means '1' and '0' means '0';
            if(str[idx] == '0'){
                ones++;
                str[idx] = '1';
            }
        }
        else{
            //means now '0' means '1' and '1' means'0'
            if(str[idx] == '1'){
                ones++;
                str[idx] = '0';
            }
        }
    }
    
    void unfix(int idx) {
       if(flips%2 == 0){
            //means i am thinking that '1' means '1' and '0' means '0';
            if(str[idx] == '1'){
                ones--;
                str[idx] = '0';
            }
        }
        else{
            //means now '0' means '1' and '1' means'0'
            if(str[idx] == '0'){
                ones--;
                str[idx] = '1';
            }
        }
    }
    
    void flip() {
       flips++;
        ones = size1 - ones;
    }
    
    bool all() {
         if(ones == size1)return true;
        return false;
    }
    
    bool one() {
         if(ones>=1) return true;
         return false;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        string ans = str;
        if(flips%2 == 1){
            for(int i=0;i<size1;i++){
                if(ans[i] == '1')ans[i] = '0';
                else if(ans[i] == '0')ans[i] = '1';
            }
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */