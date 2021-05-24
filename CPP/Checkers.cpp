#include <iostream>

int main() {
    long long white, black;
    std::cin >> white >> black;
    if(white == 0 && black == 0) std::cout << "0\n";
    else {
        if(white >= black - 1) std::cout << black << "\n";
        else std::cout << white + 1 << "\n";
    }
    return 0;
}

// white 0 black 0 -> 0 black stripes
// white 0 black 1 -> 1 black stripes
// white 0 black 100 -> 1 black stripes
//

// white 100 black 8 -> 8 black stripes
// white 8 black 8 -> same
// white 7 black 8 -> same
// white 6 black 8 -> 7 black stripes
// if(white >= black-1) black
// else if(white < black-1) white+1