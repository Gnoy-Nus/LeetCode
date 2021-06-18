class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }
        
        // 任务总数
        int m = freq.size();
        vector<int> nextValid, rest;
        for (auto [_, v]: freq) {
            nextValid.push_back(1);
            rest.push_back(v);
        }

        int time = 0;       //模拟时间
        for (int i = 0; i < tasks.size(); ++i) {
            ++time;
            int minNextValid = INT_MAX;
            for (int j = 0; j < m; ++j) {           //寻找下一个CPU可工作的时间
                if (rest[j]) {                      //还有任务没做
                    minNextValid = min(minNextValid, nextValid[j]);
                }
            }
            time = max(time, minNextValid);       //跳过待机时间
            int best = -1;
            for (int j = 0; j < m; ++j) {
                if (rest[j] && nextValid[j] <= time) {                //该任务当前时间可执行且该任务还有没做的
                    if (best == -1 || rest[j] > rest[best]) {         //寻找待执行任务数最多的一类任务
                        best = j;
                    }
                }
            }
            nextValid[best] = time + n + 1;             //更新该类任务的下次可执行时间
            --rest[best];                               //待执行任务数-1
        }

        return time;
    }
};
