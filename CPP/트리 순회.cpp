#include <iostream>

class Node {
    public:
    char name;
    Node *left;
    Node *right;
    Node() {}
    Node(char n) { name = n; }
    void front() {
        std::cout << name;
        if(left != NULL) left->front();
        if(right != NULL) right->front();
    }
    void middle() {
        if(left != NULL) left->middle();
        std::cout << name;
        if(right != NULL) right->middle();
    }
    void back() {
        if(left != NULL) left->back();
        if(right != NULL) right->back();
        std::cout << name;
    }
};

Node nodes[27];

int main() {
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        char a, b, c;
        std::cin >> a >> b >> c;
        nodes[a-'A'].name = a;
        if(b != '.') nodes[a-'A'].left = &nodes[b-'A'];
        else nodes[a-'A'].left = NULL;
        if(c != '.') nodes[a-'A'].right = &nodes[c-'A'];
        else nodes[a-'A'].right = NULL;
    }
    nodes['A'-'A'].front();
    std::cout << std::endl;
    nodes['A'-'A'].middle();
    std::cout << std::endl;
    nodes['A'-'A'].back();
    std::cout << std::endl;
}