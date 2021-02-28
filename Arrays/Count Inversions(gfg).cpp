// { Driver Code Starts


// Editorial - https://www.geeksforgeeks.org/counting-inversions/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]
long long int merge(long long arr[], long long temp[], int left, int mid, int right){
    int i=left;
    int j= mid;
    int k = left;
    long long int inv_count=0;
    
    
    while(i<=mid-1 && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv_count+= mid -i;
        }
        
    }
    while(i<= mid-1){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(i=left;i<=right;i++){
        arr[i] = temp[i];
    }
    return inv_count;
}

long long int mergesort(long long arr[], long long temp[], int left, int right){
    long long int inv_count=0;
    if(right>left){
        int mid = (right + left)/2;
        
        
        inv_count += mergesort(arr, temp, left, mid);
        inv_count += mergesort(arr, temp, mid+1, right);
        
         inv_count += merge(arr, temp, left, mid+1,right);
    }
    
    return inv_count;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long temp[N];
    long long int res = mergesort(arr,temp,0,N-1);
    return res;
}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends