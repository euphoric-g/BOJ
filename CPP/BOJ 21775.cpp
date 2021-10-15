#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

#define BLANK 0
#define NOT_USED 0
#define NEXT 0
#define ACQUIRE 1
#define RELEASE 2

class OpCard {
    public:
    int type;
    int num;
    OpCard() {}
    OpCard(std::string str) {
        type = NEXT;
    }
    OpCard(std::string str, int n) {
        num = n;
        if(str == "acquire") type = ACQUIRE;
        else type = RELEASE;
    }
};

int hand[500001] = {BLANK, };
std::queue<int> pile;
OpCard cards[500001];
std::queue<int> players;
std::unordered_map<int, int> used;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, t;
    std::cin >> n >> t;
    for(int i=0; i<t; i++) {
        int p;
        std::cin >> p;
        players.push(p);
    }
    for(int i=0; i<t; i++) {
        int id, num;
        std::string op;
        std::cin >> id >> op;
        if(op == "acquire" || op == "release") {
            std::cin >> num;
            cards[id] = OpCard(op, num);
        } else {
            cards[id] = OpCard(op);
        }
        pile.push(id);
    }
    while(t-->0) {
        int player = players.front(); players.pop();
        if(hand[player] == BLANK) {
            hand[player] = pile.front(); pile.pop();
            std::cout << hand[player] << '\n';
            switch(cards[hand[player]].type) {
                case NEXT:
                hand[player] = BLANK;
                break;
                case ACQUIRE:
                /*
                used[hand[player]]++;
                used[hand[player]]--;
                */
                if(used[cards[hand[player]].num] == NOT_USED) {
                    used[cards[hand[player]].num] = player;
                    hand[player] = BLANK;
                } else break;
                break;
                case RELEASE:
                used[cards[hand[player]].num] = NOT_USED;
                hand[player] = BLANK;
                break;
            }
        } else {
            // 핸드가 있는 경우
            std::cout << hand[player] << '\n';
            if(used[cards[hand[player]].num] == NOT_USED) {
                used[cards[hand[player]].num] = player;
                hand[player] = BLANK;
            }
        }
    }
    return 0;
}