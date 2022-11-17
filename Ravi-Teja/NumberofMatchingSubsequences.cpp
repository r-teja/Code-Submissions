class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> occurences(26);
        for(int i=0;i<s.length();i++){
            occurences[s[i]-'a'].push_back(i);
        }

        int answer, index, low, mid, high, countMatching=0;
        for(int i=0;i<words.size();i++){
            index=-1;
            for(int j=0;j<words[i].length();j++){
                low=0; 
                high=occurences[words[i][j]-'a'].size()-1; 
                answer=-1;
                while(low<=high){
                    mid=low + (high-low)/2;
                    if(occurences[words[i][j]-'a'][mid] > index){
                        answer=mid;
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                if(answer==-1){
                    break;
                }
                else{
                    index=occurences[words[i][j]-'a'][answer];
                }
            }
            if(answer > -1){
                countMatching++;
            }
        }
        return countMatching;
    }
};
