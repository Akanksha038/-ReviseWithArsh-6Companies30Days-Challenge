#define ll long long
class Solution {
public:
    bool satisfy(ll d1,ll d2,ll c1,ll c2,ll mid){
        ll div1=mid/d1;
        ll div2=mid/d2;
        ll notdiv1=mid-div1;
        ll notdiv2=mid-div2;
        ll notdivboth=mid-mid/(lcm(d1,d2));
        if(notdiv1>=c1 && notdiv2>=c2&& notdivboth>=c1+c2){
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll ans=INT_MAX, l=1,h=INT_MAX;
        while(l<=h){
            ll mid=l+(h-l)/2;
            if(satisfy(divisor1,divisor2,uniqueCnt1,uniqueCnt2,mid)){
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
                
            }
            
        }
        return ans;
        
    }
};