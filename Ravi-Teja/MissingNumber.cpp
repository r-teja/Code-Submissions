class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool hasZero=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                hasZero=true;
                break;
            }
        }
        if(!hasZero){
            return 0;
        }
        int xors = 0;
        for(int i=1;i<=(int)nums.size();i++){
            xors=xors ^i;
        }
        for(int i=0;i<nums.size();i++){
            xors=xors^nums[i];
        }
        return xors;
    }
};
