class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        int[] sus = new int[n];
        Arrays.fill(sus, 0);
        ArrayList<Integer>[]graph = (ArrayList<Integer>[])new ArrayList[n];
        for(int i = 0 ; i < n ; i++)
            graph[i] = new ArrayList<Integer>();
        for(int [] inv : invocations){
            graph[inv[0]].add(inv[1]);
        }
        // find all the suspicious nodes
        findSuspicious(k, graph, sus);
        
        List<Integer>ans = new ArrayList<>();
        // check all the edges - we can only remove  group
        // if no non sus node is invoking a sus node in the group
        for(int[] inv : invocations){
            // any sus node is invoked by a non sus one, then all nodes are added
            if(sus[inv[1]] == 1 && sus[inv[0]] == 0){
                for(int i = 0 ; i < n ; i++){
                    ans.add(i);
                }
                return ans;
            }
        }
        // otherwise add only the non sus nodes
        for(int i = 0 ; i < n ; i++){
            if(sus[i] != 1)
                ans.add(i);
        }
        
        return ans;
    }
    // find the nodes that are connected to sus node and return true
    // if false is returned this dfs has nothing to do with the sus nodes
    
    // find the suspicious nodes
    void findSuspicious(int i, ArrayList<Integer>[] graph, int[] sus){
        if(sus[i] == 1)
            return;
        sus[i] = 1;
        for(int nb : graph[i]){
            findSuspicious(nb, graph, sus);
        }
    }
}