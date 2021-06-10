class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;                         //p0指示最前面可存放0的位置，p2指示末尾存2的位置
        for (int i = 0; i <= p2; ++i) {
            while (i <= p2 && nums[i] == 2) {     //把2往末尾移动
                swap(nums[i], nums[p2]);
                --p2;
            }
            if (nums[i] == 0) {                  //把0往前面移动
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};
