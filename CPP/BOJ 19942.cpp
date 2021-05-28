#include <iostream>
#include <vector>
#include <algorithm>

class Ingredient {
    public:
    int p, f, s, v, c;
    Ingredient(){}
    Ingredient(int pp, int ff, int ss, int vv, int cc) {
        p=pp, f=ff, s=ss, v=vv, c=cc;
    }
    void show() {
        std::cout << p << ", " << f << ", " << s << ", " << v << ", " << c << '\n';
    }
    void add(Ingredient &a) {
        p += a.p, f += a.f, s += a.s, v += a.v, c += a.c;
    }
    void sub(Ingredient &a) {
        p -= a.p, f -= a.f, s -= a.s, v -= a.v, c -= a.c;
    }
};

int n;
int mp, mf, ms, mv;
std::vector<std::pair<int, std::vector<int>>> answers;
Ingredient *foods;

std::string vec_to_str(std::vector<int> vec) {
    std::string ret = "";
    for(int i=0; i<vec.size(); i++) {
        if(vec[i] == 1) ret += std::to_string(i+1);
    }
    return ret;
}

void backtracking(Ingredient &cur, std::vector<int> &selected, int depth) {
    if(depth == n) {
        if(cur.p >= mp && cur.f >= mf && cur.s >= ms && cur.v >= mv) {
            answers.push_back({cur.c, selected});
        }
        return;
    }
    selected.push_back(1);
    cur.add(foods[depth]);
    backtracking(cur, selected, depth+1);
    cur.sub(foods[depth]);
    selected.pop_back();
    selected.push_back(0);
    backtracking(cur, selected, depth+1);
    selected.pop_back();
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cin >> n >> mp >> mf >> ms >> mv;
    foods = new Ingredient[n];
    for(int i=0; i<n; i++) {
        int a, b, c, d, e;
        std::cin >> a >> b >> c >> d >> e;
        foods[i] = Ingredient(a, b, c, d, e);
    }
    int cost_min = 10000;
    auto ing = Ingredient(0, 0, 0, 0, 0);
    std::vector<int> vec;
    backtracking(ing, vec, 0);
    auto comp = [](const std::pair<int, std::vector<int>>&a, const std::pair<int, std::vector<int>>&b) -> bool {
        if(a.first != b.first) return a.first < b.first;
        return vec_to_str(a.second) < vec_to_str(b.second);
    };
    if(answers.size() == 0) {
        std::cout << "-1\n";
        return 0;
    }
    std::stable_sort(answers.begin(), answers.end(), comp);
    delete[] foods;
    std::cout << answers[0].first << '\n';
    for(int i=0; i<answers[0].second.size(); i++) {
        if(answers[0].second[i] == 1) std::cout << i+1 << ' ';
    }
    std::cout << '\n';
    return 0;
}