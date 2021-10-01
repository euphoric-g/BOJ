#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const char PLAYER = '@';
const char BLANK = '.';
const char WALL = '#';
const char ITEM_BOX = 'B';
const char SPIKE_TRAP = '^';
const char MONSTER = '&';
const char BOSS = 'M';

const int RUNNING = 0;
const int ENDED_BY_DEATH = 1;
const int ENDED_BY_WINNING = 2;
const int REVIVED = 3;

const int WEAPON = 0, ARMOR = 1, ACCESSORY = 2;

int n, m;
int state = RUNNING;
int turn = 0;
int hp = 20;
int max_hp = 20;
int atk = 2;
int def = 2;
int lv = 1;
int exp = 0;
int watk = 0;
int adef = 0;
int ac[] = {0, 0, 0, 0, 0, 0, 0};
int HR = 0, RE = 1, CO = 2, EX = 3, DX = 4, HU = 5, CU = 6;
string dead_by;
pair<int, int> spawn;
pair<int, int> cur;

int ac_num() { return ac[HR] + ac[RE] + ac[CO] + ac[EX] + ac[DX] + ac[HU] + ac[CU]; }

void give_exp(int e) {
    exp += ac[EX] ? 6*e/5 : e;
    if(exp >= 5*lv) {
        ++lv;
        max_hp += 5;
        atk += 2;
        def += 2;
        hp = max_hp;
        exp = 0;
    }
}

void give_hp(int h) {
    hp += h;
    if(hp > max_hp) hp = max_hp;
}

void give_dmg(int dmg, string s);

class object {
    private:
    public:
    char type;
    int m_atk, m_def, m_hp, m_max_hp, m_exp;
    int box_item_type, box_value;
    string name;
    object() {}
    object(char init) { type = init; }
    void set_monster_data(string n, int a, int d, int mh, int e) {
        name = n, m_atk = a, m_def = d, m_max_hp = mh, m_hp = mh, m_exp = e;
    }
    void set_box_data(int type, int value) {
        box_item_type = type, box_value = value;
    }
    void run() {
        if(type == BLANK) return;
        else if(type == WALL) perror("EXIT_WITH_UNDEFINED_BEHAVIOR");
        else if(type == SPIKE_TRAP) {
            give_dmg(ac[DX] ? 1 : 5, "SPIKE TRAP");
            if(state == REVIVED) state = RUNNING;
        } else if(type == ITEM_BOX) {
            type = BLANK;
            if(box_item_type == WEAPON) {
                watk = box_value;
            } else if(box_item_type == ARMOR) {
                adef = box_value;
            } else {
                // ACCESSORY
                if(ac_num() < 4 && !ac[box_value]) ac[box_value] = 1;
            }
        } else if(type == MONSTER) {
            // 0 : 전투 중, 1 : 승리, 2 : 패배
            int result = 0;
            // 전투 중
            do {
                int first_atk_coef;
                if(ac[CO] && ac[DX]) first_atk_coef = 3;
                else if(ac[CO]) first_atk_coef = 2;
                else first_atk_coef = 1;
                m_hp -= max(1, first_atk_coef*(atk + watk)-m_def);
                if(m_hp <= 0) {
                    result = 1;
                } else {
                    give_dmg(max(1, m_atk - (def + adef)), name);
                    if(state == ENDED_BY_DEATH) {
                        result = 2;
                    } else if(state == REVIVED) {
                        state = RUNNING;
                        result = 2;
                    }
                }
            } while(0);
            while(result == 0) {
                m_hp -= max(1, atk + watk - m_def);
                if(m_hp <= 0) {
                    result = 1;
                } else {
                    give_dmg(max(1, m_atk - (def + adef)), name);
                    if(state == ENDED_BY_DEATH) result = 2;
                    else if(state == REVIVED) {
                        state = RUNNING;
                        result = 2;
                    }
                }
            }
            // 전투 후
            if(ac[HR] && result == 1) give_hp(3);
            if(result == 1) {
                type = BLANK;
                give_exp(m_exp);
            }
        } else if(type == BOSS) {
            // HUNTER 효과
            if(ac[HU]) hp = max_hp;
            // 0 : 전투 중, 1 : 승리, 2 : 패배
            int result = 0;
            // 전투 중
            do {
                int first_atk_coef;
                if(ac[CO] && ac[DX]) first_atk_coef = 3;
                else if(ac[CO]) first_atk_coef = 2;
                else first_atk_coef = 1;
                m_hp -= max(1, first_atk_coef*(atk + watk)-m_def);
                if(m_hp <= 0) {
                    result = 1;
                } else {
                    if(!ac[HU]) give_dmg(max(1, m_atk - (def + adef)), name);
                    if(state == ENDED_BY_DEATH) {
                        result = 2;
                    } else if(state == REVIVED) {
                        state = RUNNING;
                        result = 2;
                    }
                }
            } while(0);
            while(result == 0) {
                m_hp -= max(1, atk + watk - m_def);
                if(m_hp <= 0) {
                    result = 1;
                } else {
                    give_dmg(max(1, m_atk - (def + adef)), name);
                    if(state == ENDED_BY_DEATH) result = 2;
                    else if(state == REVIVED) {
                        state = RUNNING;
                        result = 2;
                    }
                }
            }
            // 전투 후
            if(ac[HR] && result == 1) give_hp(3);
            if(result == 1) {
                type = BLANK;
                give_exp(m_exp);
                state = ENDED_BY_WINNING;
            }
        }
    }
};

object map[101][101];

void give_dmg(int dmg, string s) {
    hp -= dmg;
    if(hp <= 0) {
        if(ac[RE]) {
            ac[RE] = 0;
            hp = max_hp;
            if(map[cur.first][cur.second].type == MONSTER || map[cur.first][cur.second].type == BOSS) {
                map[cur.first][cur.second].m_hp = map[cur.first][cur.second].m_max_hp;
            }
            cur = spawn;
            state = REVIVED;
        } else {
            state = ENDED_BY_DEATH;
            dead_by = s;
            hp = 0;
        }
    }
}

void show() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << ((cur.first == i && cur.second == j && state != ENDED_BY_DEATH) ? PLAYER : map[i][j].type);
        }
        cout << '\n';
    }
    cout << "Passed Turns : " << turn << '\n';
    cout << "LV : " << lv << '\n';
    cout << "HP : " << hp << "/" << max_hp << "\n";
    cout << "ATT : " << atk << "+" << watk << '\n';
    cout << "DEF : " << def << "+" << adef << '\n';
    cout << "EXP : " << exp << "/" << 5*lv << '\n';
    switch(state) {
        case RUNNING :
        cout << "Press any key to continue.\n";
        break;
        case ENDED_BY_DEATH :
        cout << "YOU HAVE BEEN KILLED BY " << dead_by << "..\n";
        break;
        case ENDED_BY_WINNING :
        cout << "YOU WIN!\n";
        break;
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int box_cnt = 0, monster_cnt = 0;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            if(s[j] == PLAYER) {
                cur = {i, j};
                spawn = {i, j};
                map[i][j] = object(BLANK);
            } else map[i][j] = object(s[j]);
            if(s[j] == 'B') box_cnt++;
            else if(s[j] == '&' || s[j] == 'M') monster_cnt++;
        }
    }
    string op;
    cin >> op;
    reverse(op.begin(), op.end());
    for(int i=0; i<monster_cnt; i++) {
        int r, c, a, d, h, e;
        string name;
        cin >> r >> c >> name >> a >> d >> h >> e;
        map[r-1][c-1].set_monster_data(name, a, d, h, e);
    }
    for(int i=0; i<box_cnt; i++) {
        int r, c, v;
        string type, ov;
        cin >> r >> c >> type;
        if(type == "O") {
            cin >> ov;
            int ov_v;
            if(ov == "HR") ov_v = HR;
            else if(ov == "RE") ov_v = RE;
            else if(ov == "CO") ov_v = CO;
            else if(ov == "EX") ov_v = EX;
            else if(ov == "DX") ov_v = DX;
            else if(ov == "HU") ov_v = HU;
            else if(ov == "CU") ov_v = CU;
            else perror("EXIT_WITH_UNDEFINED_ACCESSORY_NAME");
            map[r-1][c-1].set_box_data(ACCESSORY, ov_v);
        } else {
            cin >> v;
            if(type == "W") map[r-1][c-1].set_box_data(WEAPON, v);
            else if(type == "A") map[r-1][c-1].set_box_data(ARMOR, v);
        }
    }
    while(state == RUNNING && !op.empty()) {
        ++turn;
        char cmd = op.back(); op.pop_back();
        int dx, dy;
        switch(cmd) {
            case 'L':
            dx = 0, dy = -1;
            break;
            case 'R':
            dx = 0, dy = 1;
            break;
            case 'U':
            dx = -1, dy = 0;
            break;
            case 'D':
            dx = 1, dy = 0;
            break;
        }
        int nx = cur.first + dx, ny = cur.second + dy;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny].type != WALL) cur = {nx, ny};
        map[cur.first][cur.second].run();
    }
    show();
}