// 76ms
// dfs bfs both can solve this problem
// use hashmap
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> uuu;
        stack<UndirectedGraphNode*> su;
        uuu[node] = new UndirectedGraphNode(node->label);
        su.push(node);
        while (su.size()){
            UndirectedGraphNode* cur = su.top();
            su.pop();
            for (int i = 0; i < cur->neighbors.size(); ++i){
                UndirectedGraphNode* neighbor = cur->neighbors[i];
                if (uuu.find(neighbor) == uuu.end()){
                    uuu[neighbor] = new UndirectedGraphNode(neighbor->label);
                    su.push(neighbor);
                }
                uuu[cur]->neighbors.push_back(uuu[neighbor]);
            }
        }
        return uuu[node];
    }
};