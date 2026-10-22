#include <bits/stdc++.h>
using namespace std;

class SegTree{
private:
    vector<int>A;
    vector<int>ST;
    void build(int node, int L, int R){
        if(L == R){
            ST[node] = A[L];
            return;
        }else{
            // find the middle element
            int mid = L + (R - L) / 2;
            // build the left child
            build(node * 2 + 1, L, mid);
            // build the right child
            build(node * 2 + 2, mid + 1, R);
            ST[node] = ST[node * 2 + 1] + ST[node * 2 + 2];
        }
    }
    int query(int node, int tl, int tr, int l, int r){
        // out of range
        if(tl > r || tr < l)
            return 0;
        // if the node contains a value within the range
        if(tl >= l && r >= tr){
            return ST[node];
        }
        // mid 
        int tm = tl + (tr - tl) / 2;
        return query(node * 2 + 1, tl, tm, l, r) + query(node * 2 + 2, tm + 1, tr, l, r);
    }
    void update(int node, int l, int r, int index, int val){
        if(l == r){
            ST[node] = val;
            A[index] = val;
            return;
        }else{
            int mid = l + (r - l) / 2;
            // left child
            if(index <= mid){
                update(node * 2 + 1, l, mid, index, val);
            }else{
                update(node * 2 + 2, mid + 1, r, index, val);
            }
        }
        ST[node] = ST[node * 2 + 1] + ST[node * 2 + 2];
    }
public:
    SegTree(int n){
        A.resize(n);
        ST.resize(4 * n);
        build(0, 0, n - 1);
    }
    SegTree(vector<int>&nums){
        int n = nums.size();
        A = nums;
        ST.resize(4 * n);
        build(0, 0, nums.size() - 1);
    }
    int query(int l, int r){
        return query(0, 0, A.size() - 1, l, r);
    }
    void update(int index, int value){
        update(0, 0, A.size() - 1, index, value);
    }

};

class NumArray {
private:
    SegTree st;
public:
    NumArray(vector<int>& nums) : st(nums) {
    }
    
    void update(int index, int val) {
        st.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return st.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */