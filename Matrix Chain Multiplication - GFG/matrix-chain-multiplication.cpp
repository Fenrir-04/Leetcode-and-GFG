//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,0));
        //return slave(1,N-1,arr,dp);
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini = 1e9;
                for(int k=i;k<j;k++){
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(steps,mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N-1];
    }
private:
    int slave(int i,int j,int arr[],vector<vector<int>>& dp){
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + slave(i,k,arr,dp) + slave(k+1,j,arr,dp);
            mini = min(steps,mini);
        }
        return dp[i][j] = mini;
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends