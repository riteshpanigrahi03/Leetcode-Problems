class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentBest=nums[0];
        int overallBest = nums[0];
        for(int i=1;i<nums.size();i++){
            if(currentBest > 0){
                currentBest+=nums[i];
            }else{
                currentBest = nums[i];
            }
            if(currentBest>overallBest){
                overallBest=currentBest;
            }
        }
        return overallBest;
        
    }
};