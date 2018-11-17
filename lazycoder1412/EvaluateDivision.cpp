class Solution {
public:
    map<string,vector<pair<string,double> > >graph;
    map<string,bool> vis;
    vector<double> ans;
    double dfs(string start,string end){
        vis[start]=true;
        if(start==end)
            return 1.0;
        for(auto nodes: graph[start])
            if(vis[nodes.first]==false){
                double temp= dfs(nodes.first,end);
                if(temp!=-1.0)
                    return temp*nodes.second;
            }
        return -1.0;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n=equations.size();
        for(int i=0;i<n;i++){
            graph[(equations[i].first)].push_back(make_pair((equations[i].second),values[i]));
            graph[(equations[i].second)].push_back(make_pair((equations[i].first),1/values[i]));
        }
        for(auto q: queries){
            vis.clear();
            if(graph[(q.first)].size()==0){
                ans.push_back(-1.0);
                continue;
            }
            ans.push_back(dfs((q.first),(q.second)));
        }
        return ans;
    }
};
