class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(sum < 0){
                sum = 0;
            }
            sum += nums[i];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};


// initialize 2 variables sum, maxi
// you have to travese the entire array
// keep on adding each element to the sum, and update maxi
// if the sum comes out to be -ve the set the sum  = zero
