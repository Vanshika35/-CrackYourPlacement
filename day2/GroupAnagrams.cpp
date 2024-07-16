class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string, int> mpp;
        // vector<vector<string>> ans;
        // for(int i = 0; i < strs.size(); i++){
        //     string temp = strs[i];
        //     sort(temp.begin(), temp.end());
        //     if(mpp.find(temp) != mpp.end()){
        //         ans[mpp[temp]].push_back(strs[i]);
        //     }else{
        //         mpp[temp] = ans.size();
        //         ans.push_back({strs[i]});
        //     }
        // }

        // return ans;
        unordered_map<string, vector<string>> mp;
        for(auto s : strs){
            string originalString = s;
            sort(s.begin(), s.end());
            mp[s].push_back(originalString);
        }
        vector<vector<string>> anagrams;
        for(auto[key, vectOfstr] : mp){
            anagrams.push_back(vectOfstr);
        }
        return anagrams;
    }
};