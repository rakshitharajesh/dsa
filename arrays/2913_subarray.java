import java.util.HashSet;
import java.util.List;
class Solution {
    public int sumCounts(List<Integer> nums) {
        int n = nums.size();
        int ans = 0;
        HashSet<Integer>set = new HashSet<>();
        for(int i = 0 ; i < n ; i++){
            set.add(nums.get(i));
            ans += 1;
            for(int j = i + 1 ; j < n ; j++){
                set.add(nums.get(j));
                ans += set.size() * set.size();
            }
            set.clear();
        }
        return ans;
    }
}