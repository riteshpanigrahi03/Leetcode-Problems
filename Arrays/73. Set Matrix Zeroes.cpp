class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        const int r= matrix.size();
        const int c= matrix[0].size();
        
        vector<bool> rowZero(r);
        vector<bool> colZero(c);
        
        for (int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    rowZero[i]=true;
                    colZero[j]=true;
                }
                
            }
        }
        for (int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(rowZero[i] ||colZero[j])
                    matrix[i][j]=0;
                
            }
            
        }
        
    }
};