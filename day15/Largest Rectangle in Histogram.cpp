class Solution {
public:
    vector<int> findNSE(vector<int>& heights){
        vector<int> temp(heights.size());
        stack<int> st;
        int n = heights.size();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            temp[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return temp;
    }
    vector<int> findPSE(vector<int>& heights){
        vector<int> temp(heights.size());
        stack<int> st;
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            temp[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return temp;
    }
    int largestRectangleArea(vector<int>& heights) {
        auto nse = findNSE(heights);
        auto pse = findPSE(heights);
        int maxi = 0;
        for(int i = 0; i < heights.size(); i++){
            maxi = max(maxi, heights[i]*(nse[i] - pse[i] - 1));
        }
        return maxi;
    }
};