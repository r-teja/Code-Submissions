class Solution {
public:
    bool static compare(pair<int,string> &a, pair<int,string> &b){
        if(a.first == b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> frequency;
        for(int i=0;i<words.size();i++){
            frequency[words[i]]++;
        }
        vector<pair<int,string>> wordsWithFrequency;
        for(auto it=frequency.begin();it!=frequency.end();it++){
            wordsWithFrequency.push_back({it->second, it->first});
        }
        sort(wordsWithFrequency.begin(), wordsWithFrequency.end(), compare);
        vector<string> result;
        for(int i=0;i<k;i++){
            result.push_back(wordsWithFrequency[i].second);
        }
        return result;
    }
};
