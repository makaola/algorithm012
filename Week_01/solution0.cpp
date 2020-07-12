//删除排序数组中的重复项
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size()<2) return nums.size();
		int pre = 0, post = 1;
		for (int post = 1; post<nums.size(); post++) {
			if (nums[post] != nums[pre]) {
				nums[++pre] = nums[post];
			}
		}
		return ++pre;
	}
};