class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> t(numRows);
        for(int i=0;i<numRows;i++){
            t[i].resize(i+1); // 0th row size = 1 | 1st row size = 2 .... 
            t[i][0]=1; //make 1st and last element of every row 1
            t[i][i]=1;
            
            for(int j=1;j<i;j++){ // from 2nd element to 2nd last element
                t[i][j]=t[i-1][j-1]+t[i-1][j];
            }
        }
        return t;
        
    }
};