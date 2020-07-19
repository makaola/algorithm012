class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        int p1 = 1, p2 = 1, p3 = 1;
        int ugly_num_a = 2, ugly_num_b = 3, ugly_num_c = 5;
        vector<int> nums(n);
        nums[0] = 1;
        for(int i=1; i<n; ++i){
            nums[i] = min(min(ugly_num_a, ugly_num_b), ugly_num_c);
            if(nums[i] == ugly_num_a) ugly_num_a = nums[p1++] * 2;
            if(nums[i] == ugly_num_b) ugly_num_b = nums[p2++] * 3;
            if(nums[i] == ugly_num_c) ugly_num_c = nums[p3++] * 5;
        }
        return nums[n-1];
    }
};
