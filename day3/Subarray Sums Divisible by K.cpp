class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // int cnt = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     int sum = 0;
        //     for(int j = i; j < nums.size(); j++){
        //         sum+=nums[j];

        //         if(sum % k == 0) cnt++;
        //     }
        // }
        // return cnt;
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;

        for(int num : nums){

            prefixSum += num;
            
            int mod = prefixSum % k;

            if(mod < 0){
                mod += k;
            }

            if(prefixMap.find(mod) != prefixMap.end()){
                count+= prefixMap[mod];
                prefixMap[mod] += 1;
            }else{
                prefixMap[mod] = 1;
            }
        }
        return count;

    }
};