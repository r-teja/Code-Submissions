class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        string tempS="";
        int start=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if((mp1.count(pattern[start])>0 || mp2.count(tempS)>0) && (mp1[pattern[start]]!=tempS || mp2[tempS]!=pattern[start])){
                    return false;
                }
                else if(mp2.count(tempS)==0 && mp1.count(pattern[start])==0){
                    mp2[tempS]=pattern[start];
                    mp1[pattern[start]]=tempS;
                }
                start++;
                if(start>pattern.length()){
                    return false;
                }
                tempS="";
            }
            else{
                tempS.push_back(s[i]);
            }
        }
        if((mp1.count(pattern[start])>0 || mp2.count(tempS)>0) && (mp1[pattern[start]]!=tempS || mp2[tempS]!=pattern[start])){
            return false;
        }
        else if(mp1.count(pattern[start])==0 && mp2.count(tempS)==0){
            mp1[pattern[start]]=tempS;
            mp2[tempS]=pattern[start];
        }
        return start == (int)pattern.length() - 1;
    }
};
