class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int id1=0;
        //find a index such that nums[index] < nums[index=1]
        for(id1=nums.size()-2;id1>=0;id1--){
            if(nums[id1]<nums[id1+1]){
                break;
            }
        }

        int i;
        if(id1<0){ // if no such index found then the array is in desc order so just reverse the array
            reverse(nums.begin(),nums.end());
        }else{
            for(i=nums.size()-1;i>id1;i--){ // else find the element from the right which is greater than the nums[id1]
                if(nums[i]>nums[id1]){
                    break;
                }
            }
            swap(nums[id1],nums[i]); // swap
            reverse(nums.begin()+id1+1,nums.end());
        }
        
        return;
        
    }
};