class RabinKarp {
private:
    int base, len, mod[2], hashVal[2];
    vector<int> p[2];
public:
    RabinKarp(){
        base = 29, len = 0;
        mod[0] = 1e9 + 9, mod[1] = 1e9 + 7;
        hashVal[0] = hashVal[1] = 0;
        p[0] = p[1] = {1};
    }
    void push_back(char ch){
        int val = ch - 'a' + 1;
        hashVal[0] = (1ll * base * hashVal[0] % mod[0] + val) % mod[0];
        hashVal[1] = (1ll * base * hashVal[1] % mod[1] + val) % mod[1];
        ++len;
    }
    void push_front(char ch){
        while(p[0].size() <= len){
            p[0].push_back(1ll * p[0].back() * base % mod[0]);
            p[1].push_back(1ll * p[1].back() * base % mod[1]);
        }
        int val = ch - 'a' + 1;
        hashVal[0] = (1ll * val * p[0][len] % mod[0] + hashVal[0]) % mod[0];
        hashVal[1] = (1ll * val * p[1][len] % mod[1] + hashVal[1]) % mod[1];
        ++len;
    }
    unsigned long long hash_value(){
        unsigned long long ret = hashVal[0];
        ret *= 1e10;
        return ret + hashVal[1];
    }
};

class Solution {
    int maxPrePlindLen(const string &s) {
        RabinKarp pre, revPre;
        int len = 0;
        for(int i = 0; i < s.size(); ++i){
            pre.push_back(s[i]);
            revPre.push_front(s[i]);
            if(pre.hash_value() == revPre.hash_value()){
                len = i+1;
            }
        }
        return len;
    }
    
public:
    string shortestPalindrome(string s) {
        int len = maxPrePlindLen(s);
        string suffixRev = "";
        for(int i = s.size() - 1; i >= len; --i) {
            suffixRev += s[i];
        }
        return suffixRev + s;
    }
};