class Solution {
public:
    int dp[14][16383];
    int dfs(int i, int mask, vector<int>& nums) {
        if (mask == (1 << nums.size()) - 1)
            return 1;
        if (dp[i][mask] == -1) {
            dp[i][mask] = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if ((mask & (1 << j)) == 0 && (mask == 0 || nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)) {
                    dp[i][mask] = (dp[i][mask] + dfs(j, mask + (1 << j), nums)) % 1000000007;
                }
            }
        }
        return dp[i][mask];
    }
    int specialPerm(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, nums);
    }
};