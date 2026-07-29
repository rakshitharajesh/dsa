class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        string res = "";
        int n = s.size();
        // map will store the latest index of each character that appears in the string
        int map[26];
        // keep track of the characters that have been included in the result
        bool visited[26] = {false};
        for(int i = 0 ; i < n ; i++){
            map[s[i] - 'a'] = i;
        }
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(visited[c - 'a'])
                continue;
           // if the last character in out answer is greater than the current character and the top character appears again, we can keep popping from out stack
            while(!st.empty() && st.top() > c && map[st.top() - 'a'] > i){
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            visited[c - 'a'] = true;
            
        }
        while(!st.empty()){
            res += st.top();st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};