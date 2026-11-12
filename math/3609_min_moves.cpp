#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        int x = tx;int y = ty;
        int cnt = 0;
        while(x >= sx && y >= sy){
            if(x == sx && y == sy)
                return cnt;
            // yi = yi-1 + yi-1
            if(y % 2 == 0 && y / 2 > x)
                y /= 2;
            // x = xi-1 + xi-1
            else if(x % 2 == 0 && x / 2 > y)
                x /= 2;
            // yi = yi-1 + xi-1
            else if(y > x){
                if(y - x > x)   
                    return -1;
                y = y - x;
            }
            // xi = xi-1 + yi-1
            else if(x > y){
                if(x - y > y)
                    return -1;
                x = x - y;
            }
            else{
                // x == y
                if(sx == 0)
                    x = 0;
                else if(sy == 0)
                    y = 0;
                else return -1;
            }
            cnt++;
        }
        return -1;

    }
};