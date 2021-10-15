#include <cstdio>
#include <vector>

using namespace std;

const unsigned int A = 0b00;
const unsigned int G = 0b01;
const unsigned int C = 0b10;
const unsigned int T = 0b11;
const char ans[] = {'A', 'G', 'C', 'T'};

int main() {
    int n;
    scanf("%d\n", &n);
    vector<unsigned int> vec;
    auto char_to_bit = [](char c) -> unsigned int {
        switch(c) {
            case 'A' : return A;
            case 'G' : return G;
            case 'C' : return C;
            case 'T' : return T;
        }
    };
    auto get_element = [](unsigned int num, int n) -> int {
        // n = 0 이면 첫번째 원소, n = 15면 마지막 원소
        return (num >> (2*n)) % 4;
    };
    auto combine = [](int t1, int t2) -> int {
        if(t1 == t2) return t1;
        if(t1 == A) {
            switch(t2) {
                case G : return C;
                case C : return A;
                case T : return G;
            }
        }
        if(t1 == G) {
            switch(t2) {
                case A : return C;
                case C : return T;
                case T : return A;
            }
        }
        if(t1 == C) {
            switch(t2) {
                case A : return A;
                case G : return T;
                case T : return G;
            }
        }
        if(t1 == T) {
            switch(t2) {
                case A : return G;
                case G : return A;
                case C : return G;
            }
        }
    };
    for(int i=0; i<n/32; i++) {
        char c;
        unsigned int num = 0;
        for(int j=0; j<16; j++) {
            scanf("%c", &c);
            num |= (char_to_bit(c) << (2*j));
        }
        vec.push_back(num);
    }
    unsigned int num = 0;
    for(int i=0; i<n%16; i++) {
        char c;
        scanf("%c", &c);
        num |= (char_to_bit(c) << (2*i));
    }
    for(int i=0; i<vec.size(); i++) {
        printf("%x\n", vec[i]);
    }
    printf("%x\n", num);
    int type = get_element(num, (n%16)-1);
    for(int i=(n%16)-2; i>=0; i--) {
        type = combine(get_element(num, i), type);
    }
    for(int i=vec.size()-1; i>=0; i--) {
        num = vec[i];
        for(int j=16; j>=0; j--) {
            type = combine(get_element(num, j), type);
        }
    }
    printf("%c\n", ans[type]);
}