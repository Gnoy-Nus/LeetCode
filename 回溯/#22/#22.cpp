class Solution {
public:
    void dfs(int n,string &combine,vector<string> &ans,int cnt){
        if(combine.size()==2*n){
            ans.push_back(combine);
            return;
        }
        if(cnt<n){
            combine.push_back('(');
            dfs(n,combine,ans,cnt+1);
            combine.pop_back();
        }
        if(combine.size()-cnt<cnt){
            combine.push_back(')');
            dfs(n,combine,ans,cnt);
            combine.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string combine;
        vector<string> ans;
        dfs(n,combine,ans,0);
        return ans;
    }
};