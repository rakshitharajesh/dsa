class Solution {
    public int openLock(String[] deadends, String target) {
        if(target.equals("0000"))
            return 0;
        HashSet<String>forbidden = new HashSet<>();
        HashSet<String>visited = new HashSet<>();
        // create a set containing the deadends
        for(String s : deadends){
            forbidden.add(s);
        }
        if(forbidden.contains("0000"))
            return -1;
        // levels will determing the number of moves
        int levels = 0;
        Queue<String>q = new ArrayDeque<>();
        // add the initial state to the queue
        q.offer("0000");
        visited.add("0000");
        while(!q.isEmpty()){
            int n = q.size();
            levels++;
            for(int i = 0 ; i < n ; i++){
                String curr = q.poll();
                char[] carray = curr.toCharArray();
                for(int j = 0 ; j < 4 ; j++){
                    // add 1 
                    char[] c1 = carray.clone();
                    c1[j] = (char)((c1[j] - '0' + 1) % 10 + '0');
                    String s1 = String.valueOf(c1);
                    if(s1.equals(target))
                        return levels;
                    // subtract 1
                    c1[j] = (char)((c1[j] - '0' - 2 + 10) % 10 + '0');
                    String s2 = String.valueOf(c1);
                    if(s2.equals(target))
                        return levels;
                    if(!forbidden.contains(s1) && !visited.contains(s1)){
                        q.offer(s1);
                        visited.add(s1);
                    }
                        
                    if(!forbidden.contains(s2) && !visited.contains(s2)){
                        q.offer(s2);
                        visited.add(s2);
                    }
                        
                }
            }
        }
        return -1;
    }
}