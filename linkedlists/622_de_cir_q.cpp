#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue {
public:
    vector<int>q;
    // the current front
    int front = -1;
    // the 
    int rear = -1;
    int k;
    int size;
    MyCircularQueue(int k) {
        q.resize(k);
        this -> k = k;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(this -> isFull())
            return false;
        size++;
        if(rear == -1){
            front = 0;
        } 
        rear = (rear + 1) % k;
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(this -> isEmpty()){
            return false;
        }
        size--;
        q[front] = -1;
        front = (front + 1) % k;
        return true;
    }
    
    int Front() {
        if(this -> isEmpty())
            return -1;
        return q[front];
    }
    
    int Rear() {    
        if(this -> isEmpty())
            return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */