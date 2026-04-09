class Solution {
public:
    bool solve(string s,string p){
        if(p.length()==0){
            return s.length()==0;
        }

        bool first_char_matched = false;
        if((s.length()>0) && (s[0]==p[0] || p[0]=='.')){
            first_char_matched = true;
        }
        if(p[1]=='*'){
            bool notTake = solve(s,p.substr(2));
            bool take = first_char_matched && solve(s.substr(1),p);
            return take || notTake;
        }
        return first_char_matched && solve(s.substr(1),p.substr(1));
    }
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};