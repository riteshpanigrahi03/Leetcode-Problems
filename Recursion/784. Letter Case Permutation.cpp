class Solution {
public:
    
    void solve(string ip,string op, vector<string>& result){
        if(ip.size()==0){
            result.push_back(op);
            return;
        }
        //if char is aphabet then 2 choices else only 1 choice
        if(isalpha(ip[0])){
            string op1=op;
            string op2=op;
            op1+=toupper(ip[0]);
            op2+=tolower(ip[0]);
            ip.erase(ip.begin());
            solve(ip,op1,result);
            solve(ip,op2,result);
            
        }else{
            string op1=op;
            op1+=ip[0];
            ip.erase(ip.begin());
            solve(ip,op1,result);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        string op="";
        solve(S,op,result);
        return result;
        
    }
};