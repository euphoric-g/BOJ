#include <iostream>

int main() {
    // 신규 확진자 100만명당 50건, 입원건수 10건 이하면 흰색
    // 신규 입원건수 30건 이상이면 빨간색
    // 나머지는 노란색
    int a, b;
    std::cin >> a >> b;
    if(a <= 50 && b <= 10) std::cout << "White\n";
    else if(b >= 30) std::cout << "Red\n";
    else std::cout << "Yellow\n";
    return 0;
}