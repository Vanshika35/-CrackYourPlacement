class Solution {
public:
    int calculate(string s) {
        stack<int> st;
       if(s.length() == 0) return 0;
       char op = '+';
       int num = 0;
       for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                num = num*10 + s[i] - '0';
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.length() - 1){
                if(op == '+'){
                    st.push(num);
                }
                if(op == '-'){
                    st.push(-num);
                }
                if(op == '*'){
                   int a = st.top();
                   st.pop();
                   st.push(a*num);
                }
                if(op == '/'){
                   int a = st.top();
                   st.pop();
                   st.push(a/num);
                }
                op = s[i];
                num = 0;
            }
       }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};