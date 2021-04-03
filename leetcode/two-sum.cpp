/**
 * Time complexity : O(n).
 * Space complexity : O(n).
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	std::unordered_map<int, int> m;
	for(int i = 0; i < nums.size(); i++) {
	    int c = target - nums[i];
	    if (m.find(c) != m.end() ) {
		return {m[c], i};
	    }
	    m.insert({nums[i], i});
	}
	return {};
    }
};
