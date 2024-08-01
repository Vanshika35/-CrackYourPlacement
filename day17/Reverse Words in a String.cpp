class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        while(iss >> word){
            words.push_back(word);
        }
        string str = "";
        for(int i = words.size() - 1; i >= 0;  i--){
            
            str+= words[i];
            str+=" ";           
        }
        if(!str.empty()){
            str.pop_back();
        }
        return str;
    }
};Basic Calculator II