#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

int main() {
    int n;
    string bin;
    int k;
    cin >> n >> bin >> k;
    if(bin.size() != n) assert(0);
    cout << (bin.find('1', bin.size()-k >= 0 ? bin.size()-k : 0) == string::npos ? "YES\n" : "NO\n");
}