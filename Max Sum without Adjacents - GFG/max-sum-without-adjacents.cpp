//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,0);
	    //return  solve(n-1,arr,dp);
	    dp[0] = arr[0];
	    for(int ind=1;ind<n;ind++){
	        int notTake = 0 + solve(ind-1,arr,dp);
            int take = arr[ind] + solve(ind-2,arr,dp);
            dp[ind] = max(take,notTake);
	    }
	    return dp[n-1];
	}
private:
    int solve(int ind,int *arr,vector<int>& dp){
        if(ind == 0) return arr[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int notTake = 0 + solve(ind-1,arr,dp);
        int take = arr[ind] + solve(ind-2,arr,dp);
        
        return dp[ind] = max(take,notTake);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends