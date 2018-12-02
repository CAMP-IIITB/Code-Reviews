class Solution
{
private:
    vector < vector<int> > tree;
    vector <int> depth;
    vector < vector<int> > ancestor;
    const int maxDepth = 21;
    int num_nodes;

public:

    Solution(vector < vector<int> > &fn_tree)
    {
        tree = fn_tree;
        num_nodes = tree.size();
        depth.resize(num_nodes+1);
        ancestor.resize(num_nodes+1);
        for(int i = 1; i <= num_nodes; i++)
        {
            ancestor[i].resize(maxDepth);
            fill(ancestor[i].begin(), ancestor[i].end(), -1);
        }
        dfs(1, -1);
        computeAncestors();
    }

    void dfs(int current, int parent)
    {
        depth[current] = depth[parent] + 1;
        ancestor[current][0] = parent;
        for(const auto &dest : tree[current])
        {
            if(dest != parent)
            {
                dfs(dest, current);
            }
        }
    }

    void computeAncestors()
    {
        for(int dep = 1; dep < maxDepth; dep++)
        {
            for(int node = 1; node <= num_nodes; node++)
            {
                if(ancestor[node][dep-1] != -1)
                {
                    ancestor[node][dep] = ancestor[ancestor[node][dep-1]][dep-1];
                }
            }
        }
    }

    int LCA(int node1, int node2)
    {
        if(depth[node1] > depth[node2])
        {
            swap(node1,node2);
        }
        int level_diff = depth[node2] - depth[node1];
        int dep = 0;
        while(level_diff > 0)
        {
            if(level_diff % 2 == 1)
            {
                node2 = ancestor[node2][dep];
            }
            level_diff /= 2;
            dep++;
        }
        if(node1 == node2)
        {
            return node1;
        }
        for(int dep = maxDepth - 1; dep >= 0; dep--)
        {
            if(ancestor[node1][dep] != ancestor[node2][dep])
            {
                node1 = ancestor[node1][dep];
                node2 = ancestor[node2][dep];
            }
        }
        return ancestor[node1][0];
    }
};
