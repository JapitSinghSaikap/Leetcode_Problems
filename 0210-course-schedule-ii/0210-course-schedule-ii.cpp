class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for (auto& it : edges) {
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        vector<int>ans;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
       
        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (int it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if(ans.size()!=V) return {};
        return ans;

    }
};