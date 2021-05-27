#include <iostream>
#include <vector>
#include <string>

int k;
std::vector<std::string> answers;
bool selected[10];

void backtracking(std::vector<char> &ineq, std::string bt, int depth) {
    if(depth == k) {
        answers.push_back(bt);
        return;
    }
    char ie = ineq[depth];
    int last = bt[bt.size()-1]-'0';
    for(int i=0; i<10; i++) {
        if(selected[i]) continue;
        if(ie == '<' && i < last) continue;
        if(ie == '>' && i > last) continue;
        selected[i] = true;
        backtracking(ineq, bt + std::to_string(i), depth+1);
        selected[i] = false;
    }
}

int main() {
    std::cin >> k;
    std::vector<char> ineq(k, 0);
    for(int i=0; i<k; i++) {
        std::cin >> ineq[i];
    }
    for(int i=0; i<10; i++) {
        selected[i] = true;
        backtracking(ineq, std::to_string(i), 0);
        selected[i] = false;
    }
    std::cout << answers[answers.size()-1] << '\n';
    std::cout << answers[0] << '\n';
    return 0;
}