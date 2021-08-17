#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int home = 'H';
const int blank = 'X';
const int jelly = 'J'; // Assassin
const int chocolate = 'C'; // Healer
const int berry = 'B'; // Mage
const int walnut = 'W'; // Tanker
const int cookiecrewbbingbbong = '#';

int main() {
    int n;
    std::cin >> n;
    int tptpmap[101][101];
    std::vector<std::pair<int, int>> ws, bs, js, cs;
    std::pair<int, int> h, ccbb;
    for(int i=0; i<n; i++) {
        std::string str;
        std::cin >> str;
        for(int j=0; j<n; j++) {
            tptpmap[i][j] = str[j];
            switch(tptpmap[i][j]) {
                case home :
                h = {i, j};
                break;
                case cookiecrewbbingbbong :
                ccbb = {i, j};
                break;
                case jelly :
                js.push_back({i, j});
                break;
                case walnut :
                ws.push_back({i, j});
                break;
                case berry :
                bs.push_back({i, j});
                break;
                case chocolate :
                cs.push_back({i, j});
                break;
            }
        }
    }
    int len_assassin = 10000, len_healer = 10000, len_mage = 10000, len_tanker = 10000;
    auto dist = [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> int {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };
    auto dist_sum = [&dist, &h, &ccbb](const std::pair<int, int> &a, const std::pair<int, int> &b, const std::pair<int, int> &c) -> int {
        return dist(h, a) + dist(a, b) + dist(b, c) + dist(c, ccbb);
    };
    len_assassin = std::min(len_assassin, dist_sum(js[0], js[1], js[2]));
    len_assassin = std::min(len_assassin, dist_sum(js[0], js[2], js[1]));
    len_assassin = std::min(len_assassin, dist_sum(js[1], js[0], js[2]));
    len_assassin = std::min(len_assassin, dist_sum(js[1], js[2], js[0]));
    len_assassin = std::min(len_assassin, dist_sum(js[2], js[0], js[1]));
    len_assassin = std::min(len_assassin, dist_sum(js[2], js[1], js[0]));
    len_healer = std::min(len_healer, dist_sum(cs[0], cs[1], cs[2]));
    len_healer = std::min(len_healer, dist_sum(cs[0], cs[2], cs[1]));
    len_healer = std::min(len_healer, dist_sum(cs[1], cs[0], cs[2]));
    len_healer = std::min(len_healer, dist_sum(cs[1], cs[2], cs[0]));
    len_healer = std::min(len_healer, dist_sum(cs[2], cs[0], cs[1]));
    len_healer = std::min(len_healer, dist_sum(cs[2], cs[1], cs[0]));
    len_mage = std::min(len_mage, dist_sum(bs[0], bs[1], bs[2]));
    len_mage = std::min(len_mage, dist_sum(bs[0], bs[2], bs[1]));
    len_mage = std::min(len_mage, dist_sum(bs[1], bs[0], bs[2]));
    len_mage = std::min(len_mage, dist_sum(bs[1], bs[2], bs[0]));
    len_mage = std::min(len_mage, dist_sum(bs[2], bs[0], bs[1]));
    len_mage = std::min(len_mage, dist_sum(bs[2], bs[1], bs[0]));
    len_tanker = std::min(len_tanker, dist_sum(ws[0], ws[1], ws[2]));
    len_tanker = std::min(len_tanker, dist_sum(ws[0], ws[2], ws[1]));
    len_tanker = std::min(len_tanker, dist_sum(ws[1], ws[0], ws[2]));
    len_tanker = std::min(len_tanker, dist_sum(ws[1], ws[2], ws[0]));
    len_tanker = std::min(len_tanker, dist_sum(ws[2], ws[0], ws[1]));
    len_tanker = std::min(len_tanker, dist_sum(ws[2], ws[1], ws[0]));
    std::vector<std::pair<int, int>> vec;
    vec.push_back({len_assassin, 0});
    vec.push_back({len_healer, 1});
    vec.push_back({len_mage, 2});
    vec.push_back({len_tanker, 3});
    std::sort(vec.begin(), vec.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool {
        if(a.first != b.first) return a.first < b.first;
        else return a.second < b.second;
    });
    std::string ans;
    switch(vec[0].second) {
        case 0 :
        ans = "Assassin\n";
        break;
        case 1 :
        ans = "Healer\n";
        break;
        case 2 :
        ans = "Mage\n";
        break;
        case 3 :
        ans = "Tanker\n";
        break;
    }
    std::cout << ans;
    return 0;
}