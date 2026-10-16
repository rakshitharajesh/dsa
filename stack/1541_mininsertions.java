package stack;import java.util.*;

class Solution {
    public int minInsertions(String s){
        int balance = 0;
        int ans = 0;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(s.charAt(i) == '('){
                balance++;
            }else{
                boolean pair = i + 1 < n && s.charAt(i + 1) == ')';
                // ( -> ))
                if(balance > 0 && pair){
                    balance--;
                    i++;
                // * -> ))
                }else if(pair){
                    ans++;
                    i++;
                // ( -> )*
                }else if(balance > 0){
                    balance--;
                    ans++;
                // * -> )*
                }else{
                    ans += 2;
                }
            }  
        }
        return ans + 2 * balance;
    }
    public int minInsertions_(String s) {
        Stack<Character>stack = new Stack<>();
        int ans = 0;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(s.charAt(i) == '(')
                stack.push(s.charAt(i));
            else{
                boolean pair = (i + 1 < n && s.charAt(i + 1) == ')');
                // ( -> ))
                if(pair && !stack.empty()){
                    stack.pop();
                    i++;
                // * -> ))
                }else if(pair){
                    ans += 1;
                    i++;
                // * -> )*
                }else if(stack.empty()){
                    ans += 2;
                // ( -> )*
                }else{
                    ans += 1;
                    stack.pop();
                }
            }
        }
        return ans + 2 * stack.size();
    }
}