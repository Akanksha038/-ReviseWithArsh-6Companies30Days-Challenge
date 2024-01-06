class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        unordered_set<string>str;
        int size=nums.size();
        for(int i=0;i<size;++i){
            for(int j=i;j<size;++j){
                string temp ; int count=0;
                for(int m=i;m<=j;++m){
                    temp.push_back(nums[m]);
                    if(nums[m]%p==0) count++;
                    if(count>k) break;
                }
                if(count<=k){
                    str.insert(temp);
                }
            }
        }
        return str.size();
        
    }
};