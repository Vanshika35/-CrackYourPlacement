class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<int, int> mpp;
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     int num = nums[i];
        //     int moreNeeded = target - num;
        //     if(mpp.find(moreNeeded) != mpp.end()){
        //         return {mpp[moreNeeded], i};
        //     }
        //     mpp[num] = i;
        // }
        // return {-1, -1};
        // map<int, int> mpp;
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     int a = nums[i];
        //     int more = target - a;
        //     if(mpp.find(more) != mpp.end()){
        //         return {mpp[more], i};
        //     }
        //     mpp[a] = i;
        // }
        // return {-1, -1};
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if (mpp.find(complement) != mpp.end()){
                return {mpp[complement], i};
            }
            mpp[nums[i]] = i;   
        }
        return {-1, -1};
    }
};
    