class Solution {
public:
    map<string, vector<pair<string, double> > >graph;
    map<string, bool> vis;
    vector<double> ans;
    double dfs(string start, string end){
        vis[start] = true;
        if(start == end)
            return 1.0;
        for(auto &nodes: graph[start])
            if (vis[nodes.first] == false) {
                double prod = dfs(nodes.first, end);
                if(prod != -1.0)
                    return prod * nodes.second;
            }
        return -1.0;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            int from = equations[i].first, to = equations[i].second;
            graph[(from)].push_back(make_pair((to), values[i]));
            graph[(to)].push_back(make_pair((from), 1/values[i]));
        }
        for(auto q: queries){
            vis.clear();
            if (graph[(q.first)].size() == 0) {
                ans.push_back(-1.0);
                continue;
            }
            ans.push_back(dfs((q.first), (q.second)));
        }
        return ans;
    }
};
