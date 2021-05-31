#include <iostream>
#include <vector>

#define MALE 1
#define FEMALE 2

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<int> switches(n+1, 0);
    for(int i=1; i<=n; i++) {
        std::cin >> switches[i];
    }
    int students;
    std::cin >> students;
    auto toggle = [](int &t) { t = (t == 0) ? 1 : 0; };
    while(students--) {
        int sex, num;
        std::cin >> sex >> num;
        if(sex == MALE) {
            for(int i=num; i<=n; i+=num) toggle(switches[i]);
        } else if(sex == FEMALE) {
            int cnt = 0;
            while(num - cnt - 1 > 0 && num + cnt + 1 <= n && switches[num-cnt-1] == switches[num+cnt+1]) cnt++;
            for(int i=num-cnt; i<=num+cnt; i++) toggle(switches[i]);
        }
    }
    for(int i=1; i<=n; i++) {
        std::cout << switches[i] << (i%20 == 0 ? '\n' : ' ');
    }
    std::cout << '\n';
    return 0;
}