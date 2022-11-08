class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int maximumUnits = 0;
        for(int i=0;i<boxTypes.size();i++){
            if(truckSize < boxTypes[i][0]){
                maximumUnits += truckSize * boxTypes[i][1];
                truckSize=0;
            }
            else{
                maximumUnits += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0]; 
            }
            if(truckSize == 0){
                return maximumUnits;
            }
        }
        return maximumUnits;
    }
};
