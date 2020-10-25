#include <iostream>
#include <map>
#include <queue>

using namespace std;

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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        
        queue<Node*> qNode;
        map<int, Node*> mapNode;

        qNode.push(node);
        while (!qNode.empty()) {
            Node *n = qNode.front();
            qNode.pop();
            Node *m = NULL;

            if (mapNode.find(n->val) == mapNode.end()) {
                m = new Node(n->val);
                mapNode[n->val] = m;
            } else {
                m = mapNode[n->val];
            }

            for (unsigned int i = 0; i < n->neighbors.size(); i++) {
                Node *t = n->neighbors[i];
                if (mapNode.find(t->val) == mapNode.end()) {
                    Node *x = new Node(t->val);
                    mapNode[t->val] = x;
                    m->neighbors.push_back(x);
                    qNode.push(t);
                } else {
                    m->neighbors.push_back(mapNode[t->val]);
                }
            }
        }

        return mapNode[node->val];
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    return 0;
}