#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int find_root(std::vector<int> &friends, int ind) {
    if(friends[ind] < 0) return ind;
    return friends[ind] = find_root(friends, friends[ind]);
}

void _union(std::vector<int> &friends, int x, int y) {
    friends[x] += friends[y];
    friends[y] = x;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t-->0) {
        int f;
        std::cin >> f;
        std::vector<int> friends(2*f+1, 0);
        std::unordered_map<std::string, int> network;
        auto touch = [&network](const std::string &name) { network[name]++; network[name]--; };
        int index = 1;
        for(int i=0; i<f; i++) {
            std::string s1, s2;
            std::cin >> s1 >> s2;
            touch(s1), touch(s2);
            if(network[s1] == 0) {
                friends[index] = -1;
                network[s1] = index++;
            }
            if(network[s2] == 0) {
                friends[index] = -1;
                network[s2] = index++;
            }

            int root_s1 = find_root(friends, network[s1]);
            int root_s2 = find_root(friends, network[s2]);
            if(root_s1 != root_s2) {
                // union
                _union(friends, root_s1, root_s2);
            } else {
                // do nothing
            }
            std::cout << -friends[root_s1] << '\n';
        }
    }
}