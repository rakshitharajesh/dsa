#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        stack<string>st;
        while(getline(ss, token, '/')){
            if(token.empty() || token == "."){
                continue;           
            }
            else if(token == ".."){
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(token);
        }
        string ans = "";
        while(!st.empty()){
           ans = '/' + st.top() + ans;
           st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};