#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define MAX_LOG 200000

int dp[MAX_LOG + 1][6];

class Log {
    public:
    std::string date;
    int lv;
    Log() {}
    Log(std::string str) {
        auto it = str.find('#');
        date = str.substr(0, it);
        lv = std::stoi(str.substr(it+1, str.size()));
    }
};

int lower_bound(std::vector<Log> &logs, std::string to_find) {
    int left = 0, right = logs.size(), mid;
    while(left < right) {
        mid = (left + right)/2;
        if(logs[mid].date >= to_find) {
            right = mid;
        } else left = mid + 1;
    }
    return right;
}

int upper_bound(std::vector<Log> &logs, std::string to_find) {
    int left = 0, right = logs.size(), mid;
    while(left < right) {
        mid = (left + right)/2;
        if(logs[mid].date > to_find) right = mid;
        else left = mid+1;
    }
    return right;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, q;
    std::cin >> n >> q;
    std::cin.ignore();
    std::vector<Log> logs;
    for(int i=0; i<n; i++) {
        std::string log;
        std::getline(std::cin, log);
        Log get = Log(log);
        logs.push_back(get);
        for(int j=0; j<6; j++) {
            if(i != 0) dp[i][j] = j < get.lv ? dp[i-1][j]+1 : dp[i-1][j];
            else dp[i][j] = j < get.lv ? 1 : 0;
        }
    }
    for(int i=0; i<q; i++) {
        std::string query;
        std::getline(std::cin, query);
        std::string date_s, date_e;
        int target_lv;
        auto it_first = query.find('#', 0);
        auto it_second = query.find('#', it_first + 1);
        date_s = query.substr(0, it_first);
        date_e = query.substr(it_first+1, it_second - it_first - 1);
        target_lv = std::stoi(query.substr(it_second+1, query.size()));
        int l = lower_bound(logs, date_s)-1;
        int r = upper_bound(logs, date_e)-1;
        if(r == -1) {
            std::cout << "0\n";
            continue;
        }
        if(l == -1) {
            std::cout << dp[r][target_lv-1] << '\n';
            continue;
        }
        int logs_cnt = dp[r][target_lv-1] - dp[l][target_lv-1];
        std::cout << logs_cnt << '\n';
    }
}