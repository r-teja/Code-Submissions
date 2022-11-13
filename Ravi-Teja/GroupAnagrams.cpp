class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        string prefix = "";
        for(int i=0;i<26;i++){
            prefix+="0";
        }
        for(int i=0;i<strs.size();i++){
            string word = strs[i]; 
            string frequency = prefix;
            for(int j=0; j<strs[i].length();j++){
                int index= strs[i][j]-'a';
                frequency[index]++;
            }
            mp[frequency].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
