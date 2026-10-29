class Solution {
public:
    int solve(int k, vector<vector<pair<int,int>>>& adj, int n){
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,k});

        while(!pq.empty()){
            int v = pq.top().second;
            // int d = pq.top().first;
            pq.pop();

            // if(d > dist[v]){
            //     continue;
            // }

            for(auto e : adj[v]){
                int neigh = e.first;
                int wt = e.second;
                if(dist[neigh] > dist[v] + wt){
                    dist[neigh] = dist[v] + wt;
                    pq.push({dist[neigh],neigh});
                }    
            } 
        }
        int ans = -1;
        for(int i=1;i<n+1;i++){
            if(dist[i] == INT_MAX){
                return -1;
            }else if(ans < dist[i]){
                ans = dist[i];
            } 
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2]; 

            adj[u].push_back({v,w});
        }

        int ans = solve(k,adj,n);

        return ans;
    }
};