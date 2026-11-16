class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        long long tak1 = 0;
        long long tak2 = 0;
        long long dp1 = 0;
        long long dp2 = 0;
        for(int i = n-1; i >=0; i--){
            tak1=nums[i];
            if(tak1%3==0) tak1-=dp1;
            else tak1+=dp1;
            tak2 = LLONG_MIN;
            if(i+1<n){
            if((1LL*nums[i]+nums[i+1])%3==0) tak2=1LL*nums[i]+nums[i+1]-dp2;
            else tak2=1LL*nums[i]+nums[i+1]+dp2;}
            long long curr = max(tak2, tak1);
            dp2 = dp1;
            dp1 = curr;
        }
        return dp1;
    }
};