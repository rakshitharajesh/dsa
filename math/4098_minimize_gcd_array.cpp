#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1)
            return -1;
        int p = value;
        int d = 2;
        while(1LL * d * d <= value){
            if(value % d == 0){
                p = d;
                break;
            }else
                    d++;
        }
        // left side feasibility
        if(index > 0 && value - p - 1LL * 2 * (index - 1) <= 0)
            return -1;
        // right side 
        if(n - 1 == index)
            return value;
        int k = n - 1 - index;
        return value + p + 1LL * (k - 1) * 2;
        
    }
};