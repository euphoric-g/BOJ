#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <string>

#define FASTIO
// #define DEBUG

#define FREE -1
#define PRINT -2

int main() {
#ifdef FASTIO
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
#endif
    int n;
    std::cin >> n;
    auto parse = [](const std::string &cmd) -> std::pair<std::string, int> {
        switch(cmd[4]) {
            case '=':
            // malloc
            return {cmd.substr(0, 4), std::stoi(cmd.substr(12, cmd.size()))};
            break;
            case '(':
            // free
            return {cmd.substr(5, 4), FREE};
            break;
            case 't':
            // print
            return {cmd.substr(6, 4), PRINT};
            break;
        }
        return {"ERROR", -1};
    };
    std::unordered_map<std::string, int> malloc_table;
    std::list<std::pair<int, int>> malloc_list;
    malloc_list.push_back({0, 0});
    malloc_list.push_back({100001, 100001});
    while(n--) {
        std::string cmd;
        std::cin >> cmd;
        std::pair<std::string, int> command = parse(cmd);
        if(command.second == FREE) {
            auto it_table = malloc_table.find(command.first);
            if(it_table != malloc_table.end() && it_table->second != 0) {
                auto it = malloc_list.begin();
                while(it->first != malloc_table[command.first]) { it++; }
                malloc_list.erase(it);
                malloc_table[command.first] = 0;
            }
        } else if(command.second == PRINT) {
            if(malloc_table.find(command.first) != malloc_table.end()) {
                std::cout << malloc_table[command.first] << '\n';
            } else {
                std::cout << "0\n";
            }
        } else {
            // malloc
            auto it = malloc_list.begin();
            int last = (it++)->second;
            while(it->first - last <= command.second) {
                if(it == malloc_list.end()) break;
                last = (it++)->second;
            }
            if(it != malloc_list.end()) {
                malloc_list.insert(it, {last+1, last+command.second});
                malloc_table[command.first] = last+1;
            } else {
                malloc_table[command.first] = 0;
            }
        }
#ifdef DEBUG
        for(const auto &pair : malloc_list) {
            std::cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        std::cout << '\n';
#endif
    }
    return 0;
}