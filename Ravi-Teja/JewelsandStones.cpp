class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> isJewel(58, 0);
        for(int i=0;i<jewels.length();i++){
            isJewel[jewels[i]-'A']++;
        }
        int numberOfJewels=0;
        for(int i=0;i<stones.length();i++){
            if(isJewel[stones[i]-'A']){
                numberOfJewels++;
            }
        }
        return numberOfJewels;
    }
};
