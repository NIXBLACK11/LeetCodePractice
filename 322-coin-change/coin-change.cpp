class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(auto coin : coins)
        {
            for(int val=coin;val<=amount;val++)
            {
                dp[val] = min(dp[val], 1+dp[val-coin]);
            }
        }
        if(dp[amount]==amount+1)
            return -1;
        return dp[amount];
    }
};