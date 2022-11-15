class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int prev=nums[0], count=1;
        for(int i=1;i<nums.size();i++){
            if(prev==nums[i]){
                count++;
            }
            else{
                count--;
                if(count==0){
                    prev=nums[i];
                    count=1;
                }
            }
        }
        return prev;
    }
};
