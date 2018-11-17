class Solution {
public:
    unordered_map<string,vector<string> >graph;
    unordered_map<string,bool> vis;
    unordered_map<string,int> val;
    void dfs(string node, int x){
        vis[node]=true;
        val[node]=x;
        for (auto c: graph[node]){
            if(!vis[c])
                dfs(c,x);
        }
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
     if(words1.size()!=words2.size())
         return false;
     for(int i=0;i<pairs.size();i++){
         graph[pairs[i].first].push_back(pairs[i].second);
         graph[pairs[i].second].push_back(pairs[i].first);
         vis[pairs[i].first]=false;
         vis[pairs[i].second]=false;
     }
     int k=0;
     for(auto x: vis){
         if(x.second==false){
             k++;
             dfs(x.first,k);
         }
      }
      for(int i=0;i<words1.size();i++){
          if(val[words1[i]]!=val[words2[i]])
              return false;
      }
      return true;
    }
};
