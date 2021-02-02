class Solution {
public:
    int balancedStringSplit(string s) {
        int splitStringCount =0;
        int count=0; // to store diff between R and L
        
        //eg -
        // s= "RLRRLL"
        //itr 1 = R => count=1
        //itr 2 = L => count-- => count=0 => splitStringCount++ => splitStringCount=1
        //itr 3 = R => count=1
        //itr 4 = R => count=2
        //itr 5 = L => count-- => count=1 
        //itr 6 = L => count-- => count=0 => splitStringCount++ => splitStringCount=2
        
        // return 2
        
        for(char& c:s){
            if(c=='R') count++;
            else if(c=='L') count--;
            
            if(count==0){
                splitStringCount++;
            }
        }
        
        return splitStringCount;
    }
};