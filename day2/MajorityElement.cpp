class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n = nums.size();
        // for(int i = 0; i < nums.size(); i++){
        //     int count = 0;
        //     for(int j = 0; j < nums.size(); j++){
        //         if(nums[i] == nums[j]){
        //             count++;
        //         }
        //     }
        //     if(count > n/2){
        //         return nums[i];
        //     }
        // }
        // return 0;
        // hashing
        // unordered_map<int, int> mpp;
        // for(int i = 0; i < nums.size(); i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it : mpp){
        //     if(it.second > n/2){
        //         return it.first;
        //     }
        // }
        // return 0;
        // MOORE VOTING ALGORITHM
        int cnt = 0;
        int ele;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                ele = nums[i];
                cnt = 1;
            }else if(nums[i] == ele){
                cnt++;
            }else{
                cnt--;
            }
        }
        return ele;
        
        
    }
};