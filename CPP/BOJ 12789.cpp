#include <iostream>
#include <vector>
#include <stack>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::queue<int> wait;
    std::stack<int> space;
    for(int i=0; i<n; i++) {
        int num;
        std::cin >> num;
        wait.push(num);
    }
    int turn = 1;
    while(1) {
        if(!space.empty() && space.top() == turn) {
            // std::cout << "find " << turn << " from stack\n";
            space.pop();
            turn++;
            continue;
        }
        while(!wait.empty() && wait.front() != turn) {
            // std::cout << "push " << wait.front() << " from queue to stack\n";
            space.push(wait.front());
            wait.pop();
        }
        if(wait.empty()) break;
        else if(wait.front() == turn) {
            // std::cout << "find " << turn << " from queue\n";
            wait.pop();
            turn++;
            continue;
        }
    }
    // std::cout << turn << '\n';
    if(turn > n) std::cout << "Nice\n";
    else std::cout << "Sad\n";
    return 0;
}