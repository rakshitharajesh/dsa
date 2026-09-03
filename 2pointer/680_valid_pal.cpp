#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else
                return false;
        }
        return true;
    }
    bool validPalindrome(string& s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            if(s[l] == s[r]){
                l++;r--;
            }else{
                if (isPalindrome(s, l + 1, r)){
                    l += 2;
                    r--;
                }else if(isPalindrome(s, l, r - 1)){
                    r -= 2;
                    l++;
                }else
                    return false;
            }
        }
        return true;
    }
};