class Solution {
public:
    void dfs(string email,
             unordered_map<string, vector<string>>& adj,
             unordered_set<string>& visited,
             vector<string>& component) {

        visited.insert(email);
        component.push_back(email);

        for (auto& neighbor : adj[email]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, vector<string>> adj;
        unordered_map<string, string> emailToName;

        // Step 1: Build the graph
        for (auto& account : accounts) {

            string name = account[0];

            for (int i = 1; i < account.size(); i++) {

                emailToName[account[i]] = name;

                if (i == 1) continue;

                adj[account[1]].push_back(account[i]);
                adj[account[i]].push_back(account[1]);
            }
        }

        // Step 2: Find connected components using DFS
        unordered_set<string> visited;
        vector<vector<string>> ans;

        for (auto& [email, name] : emailToName) {

            if (visited.find(email) == visited.end()) {

                vector<string> component;

                dfs(email, adj, visited, component);

                // Step 3: Sort emails
                sort(component.begin(), component.end());

                // Step 4: Add name
                component.insert(component.begin(), name);

                ans.push_back(component);
            }
        }

        return ans;
    }
};