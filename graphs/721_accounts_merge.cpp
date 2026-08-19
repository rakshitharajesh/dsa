class DSU{
public:
    unordered_map<string, int>rank;
    unordered_map<string, string>parent;
    DSU(){}
    string find(string a){
        if(parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
    void unionSets(string a, string b){
        string x = find(a);string y = find(b);
        if(x == y)
            return;
        if(rank[x] > rank[y])
            parent[y] = x;
        else if(rank[y] > rank[x])
            parent[x] = y;
        else{
            rank[x]++;
            parent[y] = x;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // map the email to the name
        unordered_map<string, string> emailToName;
        vector<vector<string>>ans;

        DSU dsu;
        // creating the dsu 
        for(const auto& account : accounts){
            string name = account[0];
            string firstEmail = account[1];

            for(int i = 1 ; i < account.size() ; i++){
                // if that node has not been inserted 
                // to the dsu yet
                if(!dsu.parent.count(account[i])){
                    dsu.parent[account[i]] = account[i];
                    dsu.rank[account[i]] = 0;
                }
                // union 
                dsu.unionSets(firstEmail, account[i]);
                emailToName[account[i]] = name;
            }
        }
        // each root email maps to a list of emails
        unordered_map<string, vector<string>> groups;
        for(const auto& [email, parent] : dsu.parent){
            string ancestor = dsu.find(parent);
            groups[ancestor].push_back(email);
        }
        // now we have [email1 : [e1, e2..], email2 : [e3, e4..]]
        for(auto& [root, emails] : groups){
            sort(emails.begin(), emails.end());
            vector<string>account;
            account.push_back(emailToName[root]);
            for(string email : emails)
                account.push_back(email);
            ans.push_back(account);
        }
        return ans;
    }
};