/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

bool vis[101];
unordered_map<int,Node*> mp;
unordered_map<int,Node*> mp2;
void cloneNodes(Node *u){
    if(vis[u->val]) return;
    vis[u->val] = 1;
    mp[u->val] = new Node(u->val);
    mp2[u->val] = u;
    for(auto v : u->neighbors)
        cloneNodes(v);
}


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        mp.clear(); mp2.clear(); for(int i = 0; i<101; ++i) vis[i] = 0;
        mp[node->val] = new Node(node->val);
        mp2[node->val] = node;
        Node* cur = node;
        cloneNodes(cur);
        for(auto it : mp2){
            auto clone = mp[it.first];
            for(auto v : it.second->neighbors){
                clone->neighbors.push_back(mp[v->val]);
            }
        }
        return mp[node->val];



    }
};
