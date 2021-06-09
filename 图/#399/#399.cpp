class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;

        //给点编号
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            if (variables.find(equations[i][0]) == variables.end()) {
                variables[equations[i][0]] = nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end()) {
                variables[equations[i][1]] = nvars++;
            }
        }

        // 对于每个点，存储其直接连接到的所有点及对应的权值
        vector<vector<pair<int, double>>> edges(nvars);
        for (int i = 0; i < n; i++) {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            edges[va].push_back(make_pair(vb, values[i]));
            edges[vb].push_back(make_pair(va, 1.0 / values[i]));
        }

        vector<double> ret;
        for (const auto& q: queries) {
            double result = -1.0;
            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {  //两个变量都出现过
                int ia = variables[q[0]], ib = variables[q[1]];
                if (ia == ib) {
                    result = 1.0;
                } else {                 
                //关键算法部分
                //从起点出发，通过广度优先搜索的方式，不断更新起点与当前点之间的路径长度，直到搜索到终点为止。
                    queue<int> points;
                    points.push(ia);
                    vector<double> ratios(nvars, -1.0);
                    ratios[ia] = 1.0;

                    while (!points.empty() && ratios[ib] < 0) {
                        int x = points.front();
                        points.pop();

                        for (const auto [y, val]: edges[x]) {
                            if (ratios[y] < 0) {
                                ratios[y] = ratios[x] * val;
                                points.push(y);
                            }
                        }
                    }
                    result = ratios[ib];
                }
            }
            ret.push_back(result);
        }
        return ret;
    }
};