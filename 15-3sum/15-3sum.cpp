class Solution {
    vector<vector<int>> triplets;
    int update(const int& i, const int& dir, const vector<int>& nums) {
        int newI = i;
        while(newI >= 0 && newI < nums.size() && nums[newI] == nums[i]){
            newI += dir;
        }
        return newI;
    }
    void work(const int& i, int& j, int& k, const vector<int>& nums) {
        int sum = nums[i] + nums[j] + nums[k];
        if(sum < 0) {
            j = update(j, 1, nums);
        }
        else if(sum > 0) {
            k = update(k, -1, nums);
        }
        else {
            triplets.push_back({nums[i], nums[j], nums[k]});
            j = update(j, 1, nums);
            k = update(k, -1, nums);
        }
    }
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i = update(i, 1, nums)) {
            for(int j = i+1, k = nums.size()-1; j < k; work(i, j, k, nums));
        }
        return triplets;
    }
};