class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        const int m = n*2;
        vector<int> cum(n+1);
        vector<vector<int>> idx(m+1);
        idx[n].push_back(0);
        for(int i=0;i<n;++i){
            cum[i+1] = cum[i] + (s[i] == '(' ? 1 : -1);
            idx[cum[i+1]+n].push_back(i+1);
        }
        set<int> st;
        st.insert(-1);
        st.insert(n+1);
        for(int i=0;i<=n;++i){
            st.insert(i);
        }
        int ans = 0;
        for(int i=m;i>=0;--i){
            for(int j:idx[i]){
                st.erase(j);
            }
            for(int j:idx[i]){
                auto it = st.lower_bound(j);
                int start = *--it;
                auto k = *lower_bound(idx[i].begin(),idx[i].end(),start);
                int curLen = j-k;
                ans = max(ans, curLen);
            }
            
        }
        return ans;
    }
};