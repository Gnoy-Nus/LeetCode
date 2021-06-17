class Solution {
    unordered_map<int, int> um;                    //前缀和出现次数
    int res=0;
public:
    int pathSum(TreeNode* root, int sum) {
        um[0] = 1;
        helper(root, 0, sum);
        return res;
    }

    void helper(TreeNode* root, int ps, int sum) {
        if(!root) return;
        root->val += ps;   //到达当前元素的路径上，之前所有元素的和。
        res += um[root->val - sum];   //如果两个数的前缀总和是相同的，那么这些节点之间的元素总和为零。进一步扩展相同的想法，如果前缀总和currSum，在节点A和节点B处相差target，则位于节点A和节点B之间的元素之和是target。
        
        um[root->val]++;
        helper(root->left, root->val, sum);
        helper(root->right, root->val, sum);
        um[root->val]--;
    }
};
