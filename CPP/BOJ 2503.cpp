#include <iostream>
#include <string>
#include <vector>
#include <tuple>

std::pair<int, int> compare(std::string ans, std::string guess) {
    int strike = 0, ball = 0;
    int arr[11] = {0, };
    for(int i=0; i<3; i++) arr[ans[i]-'0'] = i+1;
    for(int i=0; i<3; i++) {
        if(arr[guess[i]-'0'] == i+1) strike++;
        else if(arr[guess[i]-'0'] != 0) ball++;
    }
    // std::cout << ans << " vs " << guess << " = " << strike << "S " << ball << "B\n";
    return {strike, ball};
}

int main() {
    int n, cnt = 0;
    std::cin >> n;
    std::vector<std::tuple<std::string, int, int>> vec;
    for(int i=0; i<n; i++) {
        std::string num_in;
        int s, b;
        std::cin >> num_in >> s >> b;
        vec.push_back(std::make_tuple(num_in, s, b));
    }
    for(int i=1; i<10; i++) {
        for(int j=1; j<10; j++) {
            for(int k=1; k<10; k++) {
                if(i == j || j == k || k == i) continue;
                std::string cur = std::to_string(i) + std::to_string(j) + std::to_string(k);
                bool valid = true;
                for(int q=0; q<n && valid; q++) {
                    std::string q_num;
                    int s, b;
                    std::tie(q_num, s, b) = vec[q];
                    if(compare(cur, q_num) != std::pair<int, int>(s, b)) valid = false;
                }
                if(!valid) continue;
                cnt++;
            }
        }
    }
    std::cout << cnt << '\n';
}