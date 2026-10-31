#include <bits/stdc++.h>
using namespace std;

class MedianFinder {

private:
    priority_queue<int>lesser;
    priority_queue<int, vector<int>, greater<int>>higher;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int l = lesser.size();
        int h = higher.size();
        // 0 elements added, or the current element is lesser than the greatest element in lesser
        if(l == 0 || lesser.top() > num){
            lesser.push(num);
            if(l > h){
                // if lesser has more elements than greater move to higher
                higher.push(lesser.top());
                lesser.pop();
            }
        }else{
            // add to the greater pq
            higher.push(num);
            if(h > l){
                lesser.push(higher.top());
                higher.pop();
            }
        }
    }
    
    double findMedian() {
        if(lesser.size() < higher.size())
            return higher.top();
        return lesser.size() > higher.size() ? lesser.top() : ((double)lesser.top() + higher.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */