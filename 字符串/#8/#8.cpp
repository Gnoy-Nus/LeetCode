class Solution {
public:
    string CutSpace(string &s){
        int i=0;
        
        while(s[i]==' '&&i<s.length()){
            i++;
        }
        return s.substr(i,s.length()-i);
    }
    int analyze(string &s,bool &flag){
        if(!(s[0]>='0'&&s[0]<='9')){
            return 0;
        }
        else{
            int res=s[0]-'0',i=1;
            while(i<s.length()&&s[i]>='0'&&s[i]<='9'){
                if(res<INT_MAX/10||((res==INT_MAX/10)&&s[i]<='7')){
                    res=res*10-'0'+s[i];
                    i++;
                    flag=true;
                }
                else{    
                    res=INT_MAX;
                    flag=false;
                    break;
                }
            }
            return res;
        }
       
    }
    int myAtoi(string s) {
        string cur=CutSpace(s);
        int coef=1;
        if(cur[0]=='+'){
            coef=1;
            cur=cur.substr(1,cur.length()-1);
        }
        else if(cur[0]=='-'){
            coef=-1;
            cur=cur.substr(1,cur.length()-1);
        }
        bool flag=true;
        int res=analyze(cur,flag);
        if(res==INT_MAX&&coef==-1&&flag==false) return res*coef-1;
         return res*coef;
    }
};