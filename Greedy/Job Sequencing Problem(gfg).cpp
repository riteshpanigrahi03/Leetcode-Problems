// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends


// Prints minimum number of platforms reqquired 
bool comparator(Job a,Job b){
    return (a.profit > b.profit);
}

pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort(arr,arr+n,comparator); // sort in desc order according to profit
    int maxDeadline = arr[0].dead;
    // find the max of all deadline
    for(int i=1;i<n;i++){
        maxDeadline = max(maxDeadline, arr[i].dead);
    }
    int slots[maxDeadline+1];
    for(int i=0;i<=maxDeadline;i++){
        slots[i]= -1;
    }
    int profit =0;
    int count=0;

    //start from 1st element and we will always try to complete that job on the last day 
    //if last day is alraedy occupied then look a day before and so on..
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>0;j--){
            if(slots[j] == -1){
                slots[j]=i;
                profit+=arr[i].profit;
                count++;
                break;
            }
        }
    }
    return make_pair(count,profit);
} 

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        //function call
        pair<int,int> ans = JobScheduling(arr, n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
	return 0; 
}


  // } Driver Code Ends