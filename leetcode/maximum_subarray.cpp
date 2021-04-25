class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = -1000000000;
        int result = -1000000000;
        
        for(int i = 0; i < nums.size(); i++) {
            current_sum = std::max(current_sum + nums[i], nums[i]);
            result = std::max(result, current_sum);
        }
        return result;
    }
};
