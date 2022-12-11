class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size() >= 2){
            int firstStoneWeight=pq.top();
            pq.pop();
            int secondStoneWeight=pq.top();
            pq.pop();
            if(firstStoneWeight - secondStoneWeight > 0){
                pq.push(firstStoneWeight - secondStoneWeight);
            }
        }
        if(pq.size()){
            return pq.top();
        }
        return 0;
    }
};
