#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    map<char, int> dict;
    vector<string> ans;
    for(int i=0; i<n; i++) {
        string line;
        getline(cin, line);
        bool find = false;
        for(int j=0; j<line.size(); j++) {
            if(j == 0 || (line[j] != ' ' && line[j-1] == ' ')) {
                if(dict[toupper(line[j])] == 0) {
                    find = true;
                    dict[toupper(line[j])] = 1;
                    line = line.substr(0, j) + '[' + line[j] + ']' + line.substr(j+1, line.size());
                    break;
                }
            }
        }
        if(find) {
            ans.push_back(line);
            continue;
        }
        for(int j=0; j<line.size(); j++) {
            if(line[j] != ' ' && dict[toupper(line[j])] == 0) {
                find = true;
                dict[toupper(line[j])] = 1;
                line = line.substr(0, j) + "[" + line[j] + "]" + line.substr(j+1, line.size());
                break;
            }
        }
        ans.push_back(line);
    }
    for(const auto &st : ans) cout << st << '\n';
}