class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();
        String ans = "";
        StringBuilder firstHalf = new StringBuilder();
        char odd = '.';
        // TreeMap<Character, Integer>map = new TreeMap<>();
        int[] map = new int[26];
        for(char c : s.toCharArray()){
            map[c - 'a']++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(map[i] == 0)
                continue;
            char c = (char)((int)'a' + i);
            if(map[i] % 2 != 0)
                odd = c;
            firstHalf.append(Character.toString(c).repeat(map[i] / 2));
        }
        if(odd != '.')
            firstHalf.append(odd);
        String reversed = new StringBuilder(firstHalf.substring(0, (s.length() % 2 == 0 ? firstHalf.length() : firstHalf.length() - 1))).reverse().toString();
        return firstHalf.append(reversed).toString();
    }
}