class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int high=nums.size()-1;
            for(int j=i+1;j<nums.size();j++){
                while(nums[i]+nums[j]+nums[high]>=target and high>j)
                    high--;
                cnt+=high-j;
                if(high==j)
                    break;
            }
        }
        return cnt;
    }
};
