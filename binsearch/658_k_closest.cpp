#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        int index = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] == x){
                index = mid;
                break;
            }
            if(arr[mid] < x){
                index = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        cout << index;
        if(index < n - 1 && abs(x - arr[index]) > abs(x - arr[index + 1]))
            index++;

        left = index - 1;
        right = index + 1;
        vector<int>ans;
        ans.push_back(arr[index]);
        k--;
        while(k > 0 && left >= 0 && right < n){
            k--;
            if(x - arr[left] <= arr[right] - x){
                ans.push_back(arr[left--]);
            }else{
                ans.push_back(arr[right++]);
            }
        }
        while(k > 0 && left >= 0){
            k--;
            ans.push_back(arr[left--]);
        }
        while(k > 0 && right < n){
            k--;
            ans.push_back(arr[right++]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};