class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int nums_length=nums.size();
        for(int i=0;i<nums_length;i++){
            int start=i+1,end=nums_length-1;
            while(start<end){
                if(nums[i]+nums[start]+nums[end]==0){
                    result.push_back({nums[i], nums[start], nums[end]});
                    while(start+1<end && nums[start]==nums[start+1]){
                        start++;
                    }
                    while(end-1>start && nums[end-1]==nums[end]){
                        end--;
                    }
                    start++;
                    end--;
                }
                else if(nums[i]+nums[start]+nums[end] > 0){
                    end--;
                }
                else{
                    start++;
                }
            }
            while(i+1<nums_length && nums[i]==nums[i+1]){
                i++;
            }
        }
        return result;
    }
};
