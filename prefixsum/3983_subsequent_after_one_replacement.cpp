class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n > m)return false;
        vector<int>left(n, m);
        vector<int>right(n, -1);
        int j = 0;
        // left[i] will represent the position of the character s[i] in t => from the leftmost point
        for(int i = 0 ; i < n ; i++){
            while(j < m && s[i] != t[j])j++;
            if(j != m){
                left[i] = j;
                j++;
            }
        }
        j = m - 1;
        // right[i] will represent the position of the character s[i] in t => from the rightmost point
        for(int i = n - 1 ; i >= 0 ; i--){
            while(j >= 0 && s[i] != t[j])j--;
            if(j != -1){
                right[i] = j;
                j--;
            }
        }
        // there is no replacement required
        if(left[n - 1] != m)return true;
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                // case 1 : replace the first character
                if(n == 1) // if there is only one character then true
                    return true;
                else{
                    if(right[1] >= 1)
                        return true;
                }
            }else if(i == n - 1){
                // removing the last character
                if(left[n - 2] <= m - 2)
                    return true;
            }else{
                // case 3 : removing a middle character
                if(left[i - 1] != m && right[i + 1] != -1){
                    // there has to be enough differnce to accomodate atleast 1 character
                    // between the left character and the right character
                    if(right[i + 1] - left[i - 1] >= 2)
                        return true;
                }
            }
        }
        return false;
    }
};