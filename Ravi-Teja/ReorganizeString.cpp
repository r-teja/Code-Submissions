class Solution {
public:
    string reorganizeString(string s) {
        vector<int> frequency(26, 0);
        int n=s.length();
        for(int i=0;i<n;i++){
            frequency[s[i]-'a']++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++){
            if(frequency[i] > 0){
                pq.push({frequency[i], i+'a'});
            }
        }
        string result="";
        while(pq.size() > 1){
            pair<int,char> x=pq.top();
            pq.pop();
            pair<int,char> y=pq.top();
            pq.pop();

            result.push_back(x.second);
            result.push_back(y.second);
            x.first-=1;
            y.first-=1;

            if(x.first > 0){
                pq.push({x.first, x.second});
            }
            if(y.first > 0){
                pq.push({y.first, y.second});
            }
        }
        if(!pq.empty()){
            if(pq.top().first > 1){
                return "";
            }
            else{
                result.push_back(pq.top().second);
            }
        }
        return result;
    }
};
