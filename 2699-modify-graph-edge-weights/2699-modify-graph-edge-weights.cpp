class Solution {
    typedef long long ll;
    const int LARGE_VALUE = 2e9;
    typedef pair<long, long> P;
ll DijkstraAlgo(int n, vector<vector<int>>& edges,  int src, int dest) {
        //make the graph excluing -1 et edges
        unordered_map<ll, vector<pair<ll, ll>>> adj; //u -> (v, wt)

        for(vector<int>& edge : edges) {
            if(edge[2] != -1) {
                int u  = edge[0];
                int v  = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> result(n, INT_MAX); //result[i] = shortest path distance of src to ith node
        //vector<bool> visited(n, false); //YOU DON"T NEED VISITED ARRAY BECAUSE ANYWAYS YOU WILL NOT VISIT SAME NODE AS IT's DISTANCE WILL BE INCREASED NEXT TIME DIJKSTRA YOU WILL SKIP IT

        result[src] = 0; //src to src distance is 0
        pq.push({0, src});

        while(!pq.empty()) {
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            /*We don't need visited vector in Dijkstra
            if(visited[currNode] == true) {
                continue;
            }
            visited[currNode] = true;
            */

            for(auto&[nbr, wt] : adj[currNode]) {
                if(result[nbr] > currDist + wt) {
                    result[nbr] = currDist + wt;
                    pq.push({result[nbr], nbr});
                }
            }
        }

        return result[dest];
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDist = DijkstraAlgo(n,edges,  source, destination);

        if(currShortestDist < target) {
            return {};
        }

        bool matchedTarget = (currShortestDist == target);

        for(vector<int>& edge : edges) {
            if(edge[2] == -1) {

                edge[2] = (matchedTarget == true) ? LARGE_VALUE : 1; //assign lowest number i.e. 1

                if(matchedTarget != true) {
                    ll newShortestDist = DijkstraAlgo( n,edges, source, destination);

                    if(newShortestDist <= target) {
                        matchedTarget = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(matchedTarget == false) {
            return {};
        }
        return edges;
       
    }
};