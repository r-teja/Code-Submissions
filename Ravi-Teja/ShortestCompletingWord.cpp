class Solution {
public:
    bool isCompletingWord(string &word, vector<int> &frequencyInLicensePlate){
        vector<int> cnt=frequencyInLicensePlate;
        for(int i=0;i<word.length();i++){
            word[i]=tolower(word[i]);
            cnt[word[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(cnt[i] > 0){
                return false;
            }
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> frequencyInLicensePlate(26, 0);
        for(int i=0;i<licensePlate.length();i++){
            licensePlate[i]=tolower(licensePlate[i]);
            if(licensePlate[i]>='a' & licensePlate[i]<='z'){
                frequencyInLicensePlate[licensePlate[i]-'a']++;
            }
        }
        string result="";
        int maximum_length=INT_MAX;
        for(int i=0;i<words.size();i++){
            if(isCompletingWord(words[i], frequencyInLicensePlate) && words[i].length() < maximum_length){
                maximum_length=words[i].length();
                result=words[i];
            }
        }
        return result;
    }
};
