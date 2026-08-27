#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        for(int num : asteroids){
            bool destroyed = false;
            while(!st.empty() && st.back() > 0 && num < 0){
                if(abs(st.back()) < abs(num)){  // break the stack top
                    st.pop_back();
                    continue;
                }else if(abs(st.back()) == abs(num)){   // break the stack top
                // break the current asteroid as well
                    st.pop_back();
                    destroyed = true;
                    break;
                }else{
                    // current asteroid is destroyed
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                st.push_back(num);
            }
        }
        return st;
    }
};