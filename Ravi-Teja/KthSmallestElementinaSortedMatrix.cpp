class Solution {
public:
    int countElementsLessOrEqualsMiddle(vector<vector<int>> &matrix, int n, int value){
        int row=0, column=n-1, count=0;
        for(int i=row;i<n;i++){
            while(column >=0 && matrix[i][column]>value){
                column--;
            }
            count+= column + 1;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int minimum=matrix[0][0], maximum=matrix[n-1][n-1], answer;
        while(minimum <= maximum){
            int middle = minimum + (maximum - minimum)/2;
            if(countElementsLessOrEqualsMiddle(matrix, n, middle) >= k){
                answer=middle;
                maximum=middle-1;
            }
            else{
                minimum=middle+1;
            }
        }
        return answer;
    }
};
