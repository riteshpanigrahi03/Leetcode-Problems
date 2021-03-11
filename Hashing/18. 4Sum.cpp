class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left=j+1;
                int right = n-1;
                while(left<right){
                    int newTarget = target-nums[i]-nums[j];
                    int newSum = nums[left]+nums[right];
                    if(newSum < newTarget){
                        left++;
                    }else if(newSum > newTarget){
                        right--;
                    }else{
                        vector<int> quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[left]);
                        quad.push_back(nums[right]);
                        result.push_back(quad);
                        
                        while(left<right && nums[left]==quad[2])left++; //remove duplicates
                        while(left<right && nums[right]==quad[3])right--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return result;
    }
};