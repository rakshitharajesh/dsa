#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = nums1.size();int n2 = nums2.size();
        int i = m - 1;
        int j = n - 1;
        int pointer = n1 - 1;
        while(i >= 0 && i <= pointer && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[pointer--] = nums1[i];
                nums1[i--] = 0;
            }else{
                nums1[pointer--] = nums2[j--];
            }
        }
        while(j >= 0){
            nums1[pointer--] = nums2[j--];
        }
    }
};