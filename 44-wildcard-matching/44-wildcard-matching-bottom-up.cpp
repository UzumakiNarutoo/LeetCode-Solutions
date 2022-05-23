class Solution {
    vector<bool> dp[2];
public:
    bool isMatch(string s, string p) {
        dp[0] = dp[1] = vector<bool>(p.size() + 1, false);
        dp[s.size()&1][p.size()] = true;
        for(int j = p.size() - 1; j >= 0 && p[j] == '*'; --j){
            dp[s.size()&1][j] = true;
        }
        for(int i = s.size() - 1; i >= 0; --i) {
            dp[i&1][p.size()] = false;
            for(int j = p.size() - 1; j >= 0; --j){
                if(p[j] == '*') {
                    dp[i&1][j] = dp[i&1^1][j] | dp[i&1][j+1];
                }
                else if(p[j] == '?' || s[i] == p[j]) {
                    dp[i&1][j] = dp[i&1^1][j+1];
                }
                else {
                    dp[i&1][j] = false;
                }
            }
        }
        return dp[0][0];
    }
};
