class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //SimpleBrute Force solution
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         if(nums[i] == nums[j]){
        //             return nums[i];
        //         }
        //     }
        // }
        // return -1;
        unordered_map<int, int> mpp;
        for(auto num : nums){
            if(mpp[num] > 0){
                return num;
            }
            mpp[num]++;
        }
        // for(auto & [num, freq] : mpp){
        //     if(freq > 1) return num;
        // }
        return -1;
        // int n = nums.size();
        // vector<int> ans(n+1, 0);
        //     for(int i = 0; i < n; i++){
        //     ans[nums[i]]++;
        //     if(ans[nums[i]] > 1){
        //         return nums[i];
        //     } 
        // }
        // return -1;
    }
};