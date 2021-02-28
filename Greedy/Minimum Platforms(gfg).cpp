// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
	sort(arr,arr+n);
	sort(dep,dep+n);
	
	int platform_needed_now =1, result=1;
	int i=1,j=0; // start from the second arrival and first departure
	
	while(i<n && j<n){
	    
	    if(arr[i]<=dep[j]){ // 2nd train arrived before first train departs
	        platform_needed_now++;
	        i++;
	    }
	    else if(arr[i] > dep[j]){
	        platform_needed_now--;
	        j++;
	    }
        
	    if(platform_needed_now > result){
	        result = platform_needed_now;
	    }
	    
	    
	}
	return result;
}


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
    cout <<findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends