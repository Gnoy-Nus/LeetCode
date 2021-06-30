class Solution {
public:
   
void dfs(string& s, string& cur, int idx, int lcnt, int rcnt, int lnum, int rnum, set<string>& ans){
        if(idx == s.size()){
            if(lcnt == 0 && rcnt == 0) ans.insert(cur);     
            return;
        }
        if(lnum < rnum) return; //不合法，剪枝
        if(s[idx] == '(' && lcnt > 0){  //删除左括号
            dfs(s, cur, idx+1, lcnt-1, rcnt, lnum, rnum, ans);
        }else if(s[idx] == ')' && rcnt > 0){  //删除右括号
            dfs(s, cur, idx+1, lcnt, rcnt-1, lnum, rnum, ans);
        }
        //保留该字符
        if(s[idx] == '(') lnum++; //更新计数
        else if(s[idx] == ')') rnum++;
        cur.push_back(s[idx]);
        dfs(s, cur, idx+1, lcnt, rcnt, lnum, rnum, ans);
        cur.pop_back();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int lcnt = 0, rcnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') lcnt++;
            else if(s[i] == ')'){
                if(lcnt == 0) rcnt++;
                else lcnt--;
            }
        }
        if(lcnt == 0 && rcnt == 0) return {s};
        set<string> set;
        string str;
        dfs(s, str, 0, lcnt, rcnt, 0, 0, set);
        return {set.begin(), set.end()};
    }
};