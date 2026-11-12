#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        int x = tx;int y = ty;
        while(x >= sx && y >= sy){
            if(x == sx && y == sy)
                return true;
            if(x > y){
                // if sy is reached then x - sx has to be a multiple of y
                if(y == sy && (x - sx) % y == 0)
                    return true;
                x = x % y;
            }else{
                // if sx is reached then y - sy has to be a multiple of x
                if(x == sx && (y - sy) % x == 0)
                    return true;
                y = y % x;
            }
        }
        return false;
    }
};