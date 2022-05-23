class IndexData {
public:
    bool isVisited, isTrue;
    IndexData() {
        isVisited = isTrue = false;
    }
};
class Solution {
private:
    vector<vector<IndexData>> memo;
    bool Match(const int& i, const int& j, const string& s, const string& p) {
        if(i == s.size() && j == p.size()) {
            return true;
        }
        if(j == p.size()) {
            return false;
        }
        if(memo[i][j].isVisited) {
            return memo[i][j].isTrue;
        }
        memo[i][j].isVisited = true;
        if(i == s.size()) {
            if(p[j] == '*') {
                return memo[i][j].isTrue = Match(i, j+1, s, p);
            }
            return memo[i][j].isTrue = false;
        }
        if(p[j] == '*') {
            return memo[i][j].isTrue = Match(i, j+1, s, p) | Match(i+1, j, s, p);
        }
        if(p[j] == '?' || s[i] == p[j]) {
            return memo[i][j].isTrue = Match(i+1, j+1, s, p);
        }
        return memo[i][j].isTrue = false;
    }
public:
    bool isMatch(string s, string p) {
        memo = vector<vector<IndexData>>(s.size() + 1, vector<IndexData>(p.size() + 1));
        return Match(0, 0, s, p);
    }
};