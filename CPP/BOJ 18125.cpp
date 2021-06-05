#include <iostream>
#include <string>

std::string wink = "|>___/|        /}\n| O < |       / }\n(==0==)------/ }\n| ^  _____    |\n|_|_/     ||__|\n";
std::string sad = "|>___/|     /}\n| O O |    / }\n( =0= )\"\"\"\"  \\\n| ^  ____    |\n|_|_/    ||__|\n";

int main() {
    int r, c;
    std::cin >> r >> c;
    int og[c][r];
    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            std::cin >> og[i][j];
        }
    }
    bool flag = true;
    for(int i=0; i<r; i++) {
        for(int j=c-1; j>=0; j--) {
            int t;
            std::cin >> t;
            if(og[j][i] != t) {
                flag = false;
            }
        }
    }
    if(flag) std::cout << wink;
    else std::cout << sad;
    return 0;
}