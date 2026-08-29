#include <stack>
#include <vector>
using namespace std;
class StockSpanner {
public:
    stack<int>st;
    vector<int>prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        if(st.empty() || prices[st.top()] > price){
            // price is lesser than previous value
            st.push(prices.size() - 1);
            return 1;
        }else{
            while(!st.empty() && prices[st.top()] <= price){
                st.pop();
            }
            if(st.empty()){
                st.push(prices.size() - 1);
                return prices.size();
            }
            int top = st.top();
            st.push(prices.size() - 1);
            return prices.size() - top - 1;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */