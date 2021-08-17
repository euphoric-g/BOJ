#include <iostream>
#include <string>

typedef long long ll;

const std::string VICTORY = "Victory!\n";
const std::string DEFEAT = "gg\n";

int main() {
    ll hp, atk, enemy_hp, enemy_atk;
    std::cin >> hp >> atk >> enemy_hp >> enemy_atk;
    ll p, s;
    std::cin >> p >> s;
    ll turn = 0, enemy_turn = 0;
    
    enemy_turn += hp / enemy_atk;
    hp -= enemy_turn * enemy_atk;
    while(hp > 0) {
        hp -= enemy_atk;
        enemy_turn++;
    }

    turn += (enemy_hp - p) / atk;
    enemy_hp -= turn * atk;

    while(enemy_hp > p) {
        enemy_hp -= atk;
        turn++;
    }

    if(enemy_hp <= 0) {
        // 마왕이 스킬 발동하지 못하고 사망하는 경우
        if(turn <= enemy_turn) {
            std::cout << VICTORY;
            return 0;
        } else {
            std::cout << DEFEAT;
            return 0;
        }
    }
    ll turn_phase1 = turn;

    enemy_hp += s;

    turn += enemy_hp / atk;
    enemy_hp -= (turn - turn_phase1) * atk;

    while(enemy_hp > 0) {
        enemy_hp -= atk;
        turn++;
    }

    if(turn <= enemy_turn) {
        std::cout << VICTORY;
        return 0;
    } else {
        std::cout << DEFEAT;
        return 0;
    }
}