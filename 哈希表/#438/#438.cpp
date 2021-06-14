class Solution {
public:
bool check(int s[], int p[]) {
    for (int i = 0; i < 26; i++) {
        if (s[i] != p[i]) {
            return false;
        }
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if (p.size() > s.size()) {
        return res;
    }
    //采用数组代替哈希表，速度更快，但是要自己写判断函数
    int s_cnt[26] = { 0 };
    int p_cnt[26] = { 0 };
    for (int i = 0; i < p.size(); ++i) {//第一组
        s_cnt[s[i] - 'a']++;
        p_cnt[p[i] - 'a']++;
    }
    if (check(s_cnt,p_cnt)) {
        res.emplace_back(0);
    }

    int l = 0;
    int r = p.size() - 1;

    while (r < s.size() - 1) {
        s_cnt[s[l++] - 'a']--;  //上一组最后一个要减去
        s_cnt[s[++r] - 'a']++;  //新的一组最后一个加上
        if (check(s_cnt, p_cnt)) {
            res.emplace_back(l);
        }
    }
    return res;
}
};