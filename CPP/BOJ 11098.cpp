#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int p, max_cost = INT32_MIN;
        string max_name;
        cin >> p;
        while(p--) {
            int cost;
            string name;
            cin >> cost >> name;
            if(cost > max_cost) {
                max_cost = cost;
                max_name = name;
            }
        }
        cout << max_name << '\n';
    }
}