class Solution {
public:
 static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashtable;
        for(int num:nums){
            hashtable[num]+=1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp); 
        //堆顶是最小元素的优先队列
        for (auto& [num, count] : hashtable) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
    vector<int> ret;
    for(int i=1;i<=k;i++){
        ret.push_back(q.top().first);
        q.pop();
    }
    return ret;
    }
};