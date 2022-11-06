class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumIndex=0, maximumIndex=0, profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[minimumIndex] > prices[i]){
                minimumIndex=i;
                maximumIndex=i;
            }
            if(prices[maximumIndex] < prices[i]){
                maximumIndex=i;
            }
            if(maximumIndex > minimumIndex){
                profit=max(profit, prices[maximumIndex] - prices[minimumIndex]);
            }
        }
        return profit;
    }
};
