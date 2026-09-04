#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftHigh(n, 0);
        vector<int>rightHigh(n, 0);
        int ans = 0;
        for(int i = 1 ; i < n ; i++){
            leftHigh[i] = max(leftHigh[i - 1], height[i - 1]);
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            rightHigh[i] = max(rightHigh[i + 1], height[i + 1]);
        }
        for(int i = 0 ; i < n ; i++){
            int upper = min(rightHigh[i], leftHigh[i]);
            if(upper > height[i]) 
                ans += upper - height[i];
        }
        return ans;
    }
};