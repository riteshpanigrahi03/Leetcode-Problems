class Solution {
public:
    int minPartitions(string n) {
        // n= 32
        // 11 then n = 32 -11 =21
        // 11 then n = 21 - 11 = 10
        // 10 then n = 10 - 10 = 0
        //every time each digit is decreased by 1 
        //so here the minimum number of deci-binary numbers will be equal to greatest digit of n i.e 3 here
        int maxDigit =0;
        for(auto c:n){
            maxDigit = max(c-'0',maxDigit);
        }
        return maxDigit;
        
    }
};