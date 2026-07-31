#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val){
        this -> val = val;
        this -> key = key;
        next = nullptr;
        prev = nullptr;
    }
    Node(int key, int val, Node* prev, Node* next){
        this -> key = key;
        this -> val = val;
        this -> prev = prev;
        this -> next = next;
    }
};
class LRUCache {
private:
    unordered_map<int, Node*>map;
    int capacity;
    int size = 0;
    Node* LRU = nullptr;
    Node* MRU = nullptr;
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(map.count(key)){
            put(key, map[key] -> val);
            return map[key] -> val;
        }
        return -1;
    }
    
    void remove(int key){
        // delete a node
        Node* node = map[key];
        map.erase(key);
        if(node == LRU)
            LRU = node -> next;
        if(node == MRU)
            MRU = node -> prev;
        if(node -> prev)
            node -> prev -> next = node -> next;
        if(node -> next)
            node -> next -> prev = node -> prev;
        delete(node);
        size--;
    }
    void add(int key, int value){
        // add a node and make it MRU make map[key] = val
        Node* node = new Node(key, value);
        map[key] = node;
        if(MRU == nullptr){
            LRU = MRU = node;
        }else{
            MRU -> next = node;
            node -> prev = MRU;
            MRU = node;
        }
        size++;
    }

    void move(int key, int value){
        Node* node = map[key];
        node -> val = value;
        // if the node is already MRU, no changes
        if(MRU == node)
            return;
        // if the node was LRU, LRU changes, this node becomes MRU 
        if(node == LRU)
            LRU = node -> next;
        // detatch this node from the chain
        if(node -> prev){
            node -> prev -> next = node -> next;
        }
        if(node -> next){
            node -> next -> prev = node -> prev;
        }
        // attach it in front of old MRU, make it the new MRU
        MRU -> next = node;
        node -> prev = MRU;
        MRU = node;
    }
    void put(int key, int value) {
        if(map.count(key)){
            move(key, value);
        }else{
            // we need to create a new node
            if(size == capacity){
                // remove LRU
                remove(LRU -> key);
            }
            add(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */