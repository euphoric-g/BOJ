#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, need = 0, num = 0, lower = 0, upper = 0, special = 0;
    string s;
    cin >> n >> s;
    for(int i=0; i<s.size(); i++) {
        if(islower(s[i])) lower++;
        else if(isupper(s[i])) upper++;
        else if(isalnum(s[i])) num++;
        else special++;
    }
    if(!num) { need++; n++; }
    if(!lower) { need++; n++; }
    if(!upper) { need++; n++; }
    if(!special) { need++; n++; }
    if(n < 6) need += 6-n;
    cout << need << '\n';
}