class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        while(num > 0){
            digits.push_back(num%10);
            num=num/10;
        }
        int maximumIndex;
        for(int i=digits.size()-1;i>=0;i--){
            maximumIndex = i;
            for(int j=i-1;j>=0;j--){
                if(digits[j] >= digits[maximumIndex]){
                    maximumIndex=j;
                }
            }
            if(digits[maximumIndex] != digits[i]){
                swap(digits[i], digits[maximumIndex]);
                break;
            }
        }
        int swappedNumber=0;
        for(int i=digits.size()-1;i>=0;i--){
            swappedNumber=swappedNumber*10 + digits[i];
        }
        return swappedNumber;
    }
};
