#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int boats = 0;
        while(l <= r){
            if(people[r] + people[l] > limit){
                r--;
                boats++;
            }else{
                r--;
                l++;
                boats++;
            }
        }
        return boats;
    }
};