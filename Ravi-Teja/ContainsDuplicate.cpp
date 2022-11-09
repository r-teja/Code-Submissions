class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> isPresent;
        for(int i=0;i<nums.size();i++){
            if(isPresent.count(nums[i])==0){
                isPresent.insert(nums[i]);
            }else{
                return true;
            }
        }
        return false;
    }
};
