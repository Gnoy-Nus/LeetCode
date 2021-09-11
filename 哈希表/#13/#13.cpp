class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int cnt=0;
        int pre=0;
        for(int i=s.length();i>=0;i--){
            if(mp[s[i]]>=pre) cnt+=mp[s[i]];
            else cnt-=mp[s[i]];
            pre=mp[s[i]];
        }
        return cnt;
    }
};