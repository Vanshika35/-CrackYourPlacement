//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
    	vector<int>v;
        unordered_map<int ,int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]=i;
            v.push_back(nums[i]);
        }
        sort(v.begin(), v.end());
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(m[v[i]]!=i){
                int num1=nums[i], num2=nums[m[v[i]]];
                swap(nums[i], nums[m[v[i]]]);
                int t=m[num1];
                m[num1]=m[num2];
                m[num2]=t;
            cnt++;
            }
        }
        return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends