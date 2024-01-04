#include <vector>
class Solution {
    private:
    void helper(int index,int currentSum,int n,vector<int>&ans, vector<vector<int>>&ans2,int k){
        if(currentSum==n && k==0){ ans2.push_back(ans); return ;}
        if(currentSum>n || k==0) return ;
        for(int i=index;i<=9;i++ ){
            if(i>n){break;}
            ans.push_back(i);
            helper(i+1,currentSum+i,n,ans,ans2,k-1);
            ans.pop_back();
            
                    }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ans;
        vector<vector<int>>ans2;
        helper(1,0,n,ans,ans2,k);
        return ans2;
        
    }
};
            

