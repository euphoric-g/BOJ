#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Node {
    public:
    int number;
    bool visited;
    Node *parent;
    std::vector<Node *> subnode;
    Node() {}
    Node(int n) { number = n; visited = false; }
    int childs() {
        int cnt = 0;
        for(int i=0; i<subnode.size(); i++) {
            if(!subnode[i]->visited) cnt++;
        }
        return cnt;
    }
    int bfs() {
        int cnt = 0;
        std::queue<Node *> q;
        if(!visited) q.push(this);
        while(!q.empty()) {
            Node *current = q.front(); q.pop();
            current->visited = true;
            if(current->childs() == 0) {
                cnt++;
            } else {
                for(const auto &child : current->subnode) {
                    if(!child->visited) {
                        child->visited = true;
                        q.push(child);
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    int n;
    std::cin >> n;
    Node *nodes = new Node[n];
    int root;
    for(int i=0; i<n; i++) {
        nodes[i] = Node(i);
    }
    for(int i=0; i<n; i++) {
        int p;
        std::cin >> p;
        if( p != -1) {
            nodes[i].parent = &nodes[p];
            nodes[p].subnode.push_back(&nodes[i]);   
        } else if( p == -1) {
            nodes[i].parent = nullptr;
            root = i;
        }
    }
    int node_to_delete;
    std::cin >> node_to_delete;
    nodes[node_to_delete].bfs();
    std::cout << nodes[root].bfs() << std::endl;
    delete[] nodes;
    return 0;
}