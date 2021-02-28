// m rows and n cols
// so at max n-1 times towards right
// at max m-1 times down
//so total direction m-1 + n-1 = m+n-2
//so out of m+n-2 direction if you use combinations
    // on m-1 downwards directions m+n-2 C m-1
    // or
    // n-1 rightwards  m+n-2 C n-1

class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalDir = m+n-2;
        int r = m-1;
        double res =1;
        for(int i=1;i<=r;i++){
            res = res*(totalDir-r+i)/i;
        }
        return (int)res;
    }
};