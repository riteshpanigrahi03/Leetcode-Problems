class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // moore voting algo
        int nums1=-1;
        int nums2 = -1;
        int c1=0;
        int c2=0;
        for(int i:nums){
            if(i == nums1) 
                c1++;
            else if(i==nums2) 
                c2++;
            else if(c1==0) {
                nums1=i;
                c1++;
            }
            else if(c2==0){
                nums2=i;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        int n = nums.size();
        c1=c2=0;
        for(int i:nums){
            if(i==nums1) 
                c1++;
            else if(i==nums2) 
                c2++;
        }
        vector<int> res;
        if(c1>n/3) 
            res.push_back(nums1);
        if(c2>n/3) 
            res.push_back(nums2);
        
        return res;
        
    }
};