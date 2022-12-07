class TweetCounts {
public:
    unordered_map<string,vector<int>> mp;
    TweetCounts() {
        mp.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int value=0;
        if(freq=="minute"){
            value=60;
        }
        else if(freq == "hour"){
            value=3600;
        }
        else{
            value=86400;
        }
        int size= (endTime - startTime)/value + 1;
        vector<int> result(size,  0);
        for(auto time: mp[tweetName]){
            if(time>=startTime && time<=endTime){
                int index=(time-startTime)/value;
                result[index]++;
            }
        }
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
