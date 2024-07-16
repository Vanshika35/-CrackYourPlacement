class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int n = nums.size();
        // int j = 0;
        
        // for(int i = 1; i < n;  i++){
        //     if(nums[i] != nums[j]){
        //         nums[j+1] = nums[i];
        //         j++;
        //     }
        // }
        // return (j+1);

        // set<int> kept;
        // for(int i = 0; i < nums.size(); i++){
        //     kept.insert(nums[i]);
        // }
        // int i = 0;
        
        // for(auto it = kept.begin(); it != kept.end(); ++it){
        //     nums[i] = *it;
        //     i++;
        // }
        // return kept.size;

        int j = 0, n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[j]){
                nums[j+1] = nums[i];
                j++;
            }
        }
        return (j+1);
    }
}; 