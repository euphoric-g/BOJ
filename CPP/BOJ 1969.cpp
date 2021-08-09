#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define A 0
#define C 1
#define G 2
#define T 3

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    int sum[51][4];
    auto char_to_index = [](const char &c) -> int {
        switch(c) {
            case 'A' : return A;
            case 'C' : return C;
            case 'G' : return G;
            case 'T' : return T;
        }
    };
    auto index_to_char = [](const int &i) -> char {
        switch(i) {
            case A : return 'A';
            case C : return 'C';
            case G : return 'G';
            case T : return 'T';
        }
    };
    for(int i=0; i<51; i++) {
        for(int j=0; j<4; j++) {
            sum[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++) {
        std::string str;
        std::cin >> str;
        for(int j=0; j<m; j++) {
            sum[j][char_to_index(str[j])]++;
        }
    }
    std::string dna = "";
    int hamming_dist = 0;
    for(int i=0; i<m; i++) {
        int max_type = A, max_value = sum[i][A];
        for(int j=C; j<=T; j++) {
            if(max_value < sum[i][j]) {
                max_type = j;
                max_value = sum[i][j];
            }
        }
        dna += index_to_char(max_type);
        hamming_dist += sum[i][A] + sum[i][C] + sum[i][G] + sum[i][T] - max_value;
    }
    std::cout << dna << '\n' << hamming_dist << '\n';
}