class Solution {
public:
    double myPow(double x, int n) {
        double ans =1;
        
        long long n1 = abs(n);
        while(n1>0){
            if(n1%2==0){
                x=x*x;
                n1/=2;
            }else{
                ans*=x;
                n1-=1;
            }
        }
        if(n<0) return double(1.0)/ans;
        return ans;
        
    }
};