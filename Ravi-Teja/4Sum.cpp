class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int numsSize=nums.size();

        //Sorting
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        // O(N^3) with two pointer approach

        long long temporaryTarget ;
        for(int i=0;i<numsSize;i++){
            for(int j=i+1;j<numsSize;j++){
                int left=j+1, right=numsSize-1;
                temporaryTarget = (long long)target - (long long)(nums[i]+nums[j]);
                while(left < right){
                    if(nums[left] + nums[right] == temporaryTarget){
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left<right && nums[left]==nums[left-1]){
                            left++;
                        }
                        while(left<right && nums[right]==nums[right+1]){
                            right--;
                        }
                        if(left >= right){
                            break;
                        }
                    }
                    else if(nums[left] + nums[right] > temporaryTarget){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
                j++;
                while(j-1>=0 && j<numsSize && nums[j]==nums[j-1]){
                    j++;
                }
                j--;
            }
            i++;
            while(i-1>=0 && i<numsSize && nums[i]==nums[i-1]){
                i++;
            }
            i--;
        }

        return result;
    }
};
