//法一：从后往前模拟
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        bool dp[n];
        for(int i=n-2;i>=0;--i){
            int j=nums[i];
            if(i+j>=n-1){
                dp[i]=true;
                continue;
            }
            for(j=nums[i];j>=1;--j){
                if(dp[i+j]==true){
                    dp[i]=true;
                    break;
                }
            }
            if(j==0) dp[i]=false;
        }
        return dp[0];
    }
};

//法二：依次遍历数组中的每一个位置，并实时维护 最远可以到达的位置
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};