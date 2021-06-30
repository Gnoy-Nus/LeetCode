class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        // f[i][0]: 手上持有股票的最大收益， 第i-1天就持有了，或者第i天开始持有（要求前一天结束时为手上没有股票且未开始冷冻期）
        // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益 （将前一天持有的股票今天卖出，进入冷冻期）
        // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益, （继续不持有，前一天可能是冷冻期也可能不是）
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};