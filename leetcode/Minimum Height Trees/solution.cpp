// 1256ms
// root rotation solution
// O(n) time and O(n) space
class Solution {
public:
    unordered_map<int, vector<int> > M;
    int N;

    int dfs(int node){
        int max_depth = 0;
        M[node][M[node].size() - 1] = -1;
        for (int i = 0; i < M[node].size() - 1; ++i){
            int next_node = M[node][i];
            if (M[next_node][M[next_node].size() - 1] != 0) continue;
            max_depth = max(max_depth, dfs(next_node) + 1);
        }
        return M[node][M[node].size() - 1] = max_depth;
    }

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        ret.push_back(0);
        if (edges.size() == 0) return ret;

        N = n;
        M.clear();

        // constract the graph. O(n)
        for (auto p : edges){
            int a = p.first, b = p.second;
            M[a].push_back(b);
            M[b].push_back(a);
        }

        // the last element will record the depth of that node
        for (int i = 0; i < N; ++i) M[i].push_back(0);

        // treat 0 as root first
        // dfs to get the depth of each node. O(n)
        int depth = dfs(0);

        // rotate the root of the tree to get the shortested. O(n)
        int root = 0;
        while (true){
            ret.clear();
            ret.push_back(root);
            map<int, int> mii;
            int new_root;
            for (int i = 0; i < M[root].size() - 1; ++i){
                int next_node = M[root][i];
                mii[M[next_node][M[next_node].size() - 1] * -1]++;
                if (mii.begin()->first * -1 == M[next_node][M[next_node].size() - 1]){
                    new_root = next_node;
                }
            }
            map<int, int>::iterator it = mii.begin();
            if (it->second > 1) break;

            // transfer the node of deepest sub-tree as the root
            mii.erase(it);
            int last_depth = M[root][M[root].size() - 1];
            if (mii.size()) M[root][M[root].size() - 1] = mii.begin()->first * -1 + 1;
            else M[root][M[root].size() - 1] = 0;
            if (last_depth == M[new_root][M[new_root].size() - 1]){
                ret.push_back(new_root);
                break;
            }
            root = new_root;
        }
        return ret;
    }
};

// another solution from others
// also 1200+ms
// the idea is different that is leaf deleting
// this solution is shorted
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_set<int> sets;
        for (int i=0; i < n; ++i) {
            sets.insert(i);
        }
        vector<unordered_set<int>> graph(n);
        for (auto e : edges) {
            int x=e.first, y=e.second;
            graph[x].insert(y);
            graph[y].insert(x);
        }
        vector<int> curr, next;
        for (int i=0; i < n; ++i) {
            if (graph[i].size() == 1) {
                curr.push_back(i);
            }
        }
        for (; sets.size() > 2; ) {
            for (auto i : curr) {
                sets.erase(i);
                int j=*(graph[i].begin());
                graph[i].erase(j);
                graph[j].erase(i);
                if (graph[j].size() == 1) {
                    next.push_back(j);
                }
            }
            curr = next; next.clear();
        }
        vector<int> ret(sets.begin(), sets.end());
        sort(ret.begin(), ret.end());
        return ret;
    }
};