class Solution {
public:
    int solve(string s,string t){
        int n = s.size();
        vector<int> prev(n+1,0), cur(n+1,0);
       /* for(int i=0;i<=n;i++){
            dp[0][i] = 0;
            dp[i][0] = 0;
        }*/
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j] , cur[j-1]);
            }
            prev = cur;
        }
        return prev[n];
    }
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int a = solve(s,t);
        int n = s.size();
        
        return abs(n-a);
    }
};