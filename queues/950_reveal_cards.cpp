#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        int mid = (n + 1) / 2;
        vector<int>ans(n);
        queue<int>q;
        int index = 0;
        for(int i = 0 ; i < n ; i++)q.push(i);
        for(int card : deck){
            ans[q.front()] = card;q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};