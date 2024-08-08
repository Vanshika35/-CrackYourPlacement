//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool possible(int N, int sum, int arr[]){
         vector<vector<int>> dp(N+1, vector<int>(sum+1, -1));
        if(N == 0){
            return sum == 0 ? 1 : 0;
        }
        int take = 0, notake = 0;
        if(dp[N][sum] != -1) return dp[N][sum];
        if(arr[N-1] <= sum){
             take = possible(N-1, sum-arr[N-1], arr);
        }
        notake = possible(N-1, sum, arr);
        return dp[N][sum] = take || notake;
    }
    bool checkPartition(int N, int arr[]){
        int totalSum = 0;
        for(int i = 0; i < N; i++){
            totalSum += arr[i];
        }
        if(totalSum%2 == 1) return false;
        else{
            totalSum = totalSum/2;
        }
       
        return possible(N, totalSum, arr);
    }
    int equalPartition(int N, int arr[])
    {
        return checkPartition(N, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends