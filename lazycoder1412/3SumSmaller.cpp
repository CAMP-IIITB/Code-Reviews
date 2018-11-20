class Solution {
public:
    int threeSumSmaller(const vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0, siz = nums.size();
        for(int i = 0; i < siz; i++){
            int high = siz - 1;
            for (int j = i + 1; j < siz; j++) {
                while (nums[i] + nums[j] + nums[high] >= target and high > j)
                    high--;
                cnt += high - j;
                if (high == j)
                    break;
            }
        }
        return cnt;
    }
};
