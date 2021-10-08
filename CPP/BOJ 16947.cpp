#include <iostream>
#include <vector>

class Station {
    public:
    std::vector<Station *> next;
    bool visited;
    bool circular;
    bool jisun;
    Station() { circular = false; visited = false; jisun = false; }
    void DFS(std::vector<Station *> *route) {
        visited = true;
        std::cout << "DFS entered... next.size() = " << next.size() << std::endl;
        if(next.size() == 3) {
            // route에 위치한 모든 지점 : circular
            for(const auto& ptr : next) {
                ptr->circular = true;
            }
        } else if(next.size() == 1) {
            // route에 위치한 모든 지점 : jisun
            for(const auto& ptr : next) {
                ptr->jisun = true;
            }
        } else {
            // 현재 지점을 route에 넣고 다음 역으로 이동
            visited = true;
            route->push_back(this);
            for(const auto &ptr : next) {
                if(!ptr->visited) ptr->DFS(route);
            }
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Station> line = std::vector<Station>(n, Station());
    for(int i=0; i<n; i++) {
        int a, b;
        std::cin >> a >> b;
        line[a-1].next.push_back(&line[b-1]);
        line[b-1].next.push_back(&line[a-1]);
    }
    for(int i=0; i<n; i++) {
        if(line[i].next.size() == 3) {
            line[i].visited = true;
            line[i].circular = true;
            line[i].jisun = true;
            for(const auto &next_station : line[i].next) {
                if(!next_station->visited) {
                    std::cout << "call dfs from station #" << i+1 << "]\n";
                    std::vector<Station *> route;
                    next_station->DFS(&route);
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        std::cout << "Station #" << i+1 << " : jisun = " << (line[i].jisun ? "TRUE " : "FALSE ")
        << "circular = " << (line[i].circular ? "TRUE\n" : "FALSE\n");
    }   
}