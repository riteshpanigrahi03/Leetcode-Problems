class Solution {
public:
    void combinations(int index,vector<int>& candidates,int target, vector<vector<int>>& result, vector<int>& d,int n){
        
        if(index == n ){
            if(target ==0){
                result.push_back(d);
            }
            return;
        }
        
        if(candidates[index]<= target){
            d.push_back(candidates[index]);
            combinations(index,candidates,target-candidates[index],result,d,n);
            d.pop_back();
        }
        combinations(index+1,candidates,target,result,d,n);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> d;
        int n= candidates.size();
        combinations(0,candidates,target,result,d,n);
        return result;
    }
};