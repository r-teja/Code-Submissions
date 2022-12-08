class Solution {
public:
    void countFrequency(unordered_map<string,int> &frequency, string &s){
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                frequency[temp]++;
                temp="";
            }
            else{
                temp.push_back(s[i]);
            }
        }
        frequency[temp]++;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> frequency;
        countFrequency(frequency, s1);
        countFrequency(frequency, s2);
        vector<string> result;
        for(auto it=frequency.begin();it!=frequency.end();it++){
            if(it->second==1){
                result.push_back(it->first);
            }
        }
        return result;
    }
};
