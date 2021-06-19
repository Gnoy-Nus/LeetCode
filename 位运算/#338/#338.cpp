//法一：内置函数__builtin_popcount()
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        for(int i=0;i<=n;i++) ret.push_back(__builtin_popcount(i&i));
        return ret;
    }
};

//法二：动态规划——最低有效位
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
};

