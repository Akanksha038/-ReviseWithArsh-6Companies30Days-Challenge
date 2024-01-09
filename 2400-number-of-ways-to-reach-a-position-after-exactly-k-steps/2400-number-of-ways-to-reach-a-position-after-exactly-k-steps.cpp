class Solution {
    int mod=1e9 + 7;
    int f(int current,int lp,int k, vector<vector<int>>&dp){
        //base case
        if(k==0){
            return current==lp;
            
        }
        if(dp[k][current+1000]!=-1) return dp[k][current+1000];
        return dp[k][current+1000]=(f(current+1,lp,k-1,dp)%mod+f(current-1,lp,k-1,dp)%mod)%mod;
    }
    
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(k+1,vector<int>(4000,-1));
        if(startPos>endPos){
            swap(startPos,endPos);
        }
        int diff=endPos-startPos;
        if(diff%2!=k%2) return 0;
        return f(startPos,endPos,k,dp);
        
    }
};