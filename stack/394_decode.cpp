#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<int>count;
        stack<string>st;
        string curr = "";
        
        int k = 0;
        for(char c : s){
            if(isdigit(c)){
                k = k * 10 + (c - '0');
            }else if(c == '['){
                count.push(k);
                st.push(curr);
                k = 0;
                curr = "";
            }else if(c == ']'){
                int times =  count.top();count.pop();
                string str = curr;
                curr = st.top();st.pop();
                for(int i = 0 ; i < times ; i++){
                    curr += str;
                }
            }else{
                curr += c;
            }
        }
        return curr;

    }
    
};