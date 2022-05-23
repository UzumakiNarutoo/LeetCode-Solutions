class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isAppear(n);
        for(int num : nums) {
            if( num >= 1 && num <= n ){
                isAppear[num - 1] = 1; /// zero based
            }
        }
        for(int i=1; i<n+1; ++i){
            if(!isAppear[i-1]){
                return i;
            }
        }
        return n+1;
    }
};