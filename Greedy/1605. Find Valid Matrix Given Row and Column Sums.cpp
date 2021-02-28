class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> A(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0 ; j < n; ++j) {
                A[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= A[i][j];
                colSum[j] -= A[i][j];
            }
        }
        return A;
        
    }
};

/*
Example
rowSum = [3,8], colSum = [4,7]
loop starts

i=0, j=0
A[0][0] = min (3,4) = 3
rowSum = [0,8], colSum = [1,7]

i=0, j=1
A[0][1] = min (0,7) = 0
rowSum = [0,8], colSum = [1,7]

i=1, j=0
A[1][0] = min (8,1) = 1
rowSum = [0,7], colSum = [0,7]

i=1, j=1
A[1][1] = min (7,7) = 7
rowSum = [0,0], colSum = [0,0]

[
    [3,0],
    [1,7]
]
*/