#include <vector>
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <tuple>

class Problem {
    public:
    std::map<std::string, std::tuple<bool, int, int>> status;
    // status[team_name] = {ACCEPTED or REJECTED, # of submissions, sum of times}
    Problem() {}
    void submit(int time, std::string team_name, char result) {
        if(status.find(team_name) == status.end()) {
            status[team_name] = std::make_tuple((result == 'A' ? true : false), 1, (result == 'A' ? time : 0));
            return;
        }
        bool res;
        int subs, sum;
        std::tie(res, subs, sum) = status[team_name];
        if(res) return;
        if(result == 'A') status[team_name] = std::make_tuple(true, subs+1, time);
        else status[team_name] = std::make_tuple(res, subs+1, sum);
    }
    std::tuple<int, double, double> get_data() {
        int accepted_teams = 0;
        double sum_subs = 0, sum_times = 0;
        for(const auto &item : status) {
            bool res;
            int subs, sum;
            std::tie(res, subs, sum) = item.second;
            if(res) {
                accepted_teams++;
                sum_subs += subs;
                sum_times += sum;
            }
        }
        sum_subs /= accepted_teams;
        sum_times /= accepted_teams;
        return std::make_tuple(accepted_teams, sum_subs, sum_times);
    }
};

int main() {
    int n;
    std::cin >> n;
    Problem problems[9];
    while(n--) {
        int time;
        std::string team_name;
        char problem, result;
        std::cin >> time >> team_name >> problem >> result;
        problems[problem-'A'].submit(time, team_name, result);
    }
    for(int i=0; i<9; i++) {
        int accepted_teams;
        double sub, time;
        std::tie(accepted_teams, sub, time) = problems[i].get_data();
        if(accepted_teams > 0)
        std::cout << (char)('A' + i) << ' ' << std::fixed << std::setprecision(2) << accepted_teams << ' ' << sub << ' ' << time << '\n';
        else
        std::cout << (char)('A' + i) << ' ' << accepted_teams << '\n';
    }
}