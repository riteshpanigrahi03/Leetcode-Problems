//problem link- https://www.interviewbit.com/problems/partitions/
int Solution::solve(int A, vector<int> &B) {
    int ans=0;
    int sum=0;
    for(int i=0;i<A;i++){
        sum+=B[i];
        
    }
    //cout<<sum;
    if(sum%3!=0){
        return ans;
    }
    vector<int> temp(A,0);
    int tempSum=0;
    int num1=sum/3;
    for(int i=A-1;i>=0;i--){
        tempSum+=B[i];
        if(tempSum==num1){
            temp[i]=1;
        }
    }
    tempSum=0;
    for(int i=0; i <A; i++){
        tempSum+=B[i];
        if(tempSum==num1){
            for(int j=i+2;j<A;j++){
                if(temp[j]==1){
                    ans+=1;
                }
            }
        }
    }
    
    return ans;
}


//Explanation
// I will explain you how I worked up my solution. Lets get basic case right first. 
// Sum of the given array must be a multiple of 3 for any chance of it having 3 partitions.
// Next we create a suffix array, which will have a note of position where the sum is (sum/3) from the end.
// Therefore when we iterate from front, (keeping sum count) as soon as we reach (sum/3) let say at i, 
// we have probably got our 1st part(still there can be a chance that 3 partitions won’t exist).
//  Now as we are looking for 3 parts, the 3rd part will start from i+2 or thereafter (2nd part can be at i+1).
//   Therefore from i+2 position we check on our suffix array for instances where we tagged positions as 1. In all the places we find that,
//  we have a successful case of 3 partition and we increase a totalCount by 1. 
// Then we resume from out i th index and do the same again when the sum is (sum/3).

// reference- https://discuss.interviewbit.com/t/can-any-explain-me-the-solution/44381