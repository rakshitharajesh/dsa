#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>visited;
        // a bfs approach with a queue
        queue<string>q;
        q.push(beginWord);
        visited.insert(beginWord);
        unordered_set<string>wordL;
        wordL.insert(wordList.begin(), wordList.end());
        int moves = 1;
        while(!q.empty()){
            int n = q.size();
            moves++;
            for(int i = 0 ; i < n ; i++){
                string curr = q.front();q.pop();
                for(int j = 0 ; j < curr.size() ; j++){
                    string newcurr = curr;
                    for(char c = 'a' ; c <= 'z' ; c++){
                        newcurr[j] = c;
                        if(!visited.count(newcurr) && wordL.count(newcurr)){
                            if(newcurr == endWord)  
                                return moves;
                            q.push(newcurr);
                            visited.insert(newcurr);
                        }
                    }
                }
            }
        }
        return 0;
    }
};