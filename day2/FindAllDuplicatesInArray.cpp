class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // USING MAP DATA STRUCTURE
        unordered_map<int, int> temp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            temp[nums[i]]++;
        }
        for(auto it : temp){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};