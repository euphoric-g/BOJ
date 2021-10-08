#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t-->0) {
        int N, M, k, D;
        std::cin >> N >> M >> k >> D;
        /*
지역리그 N개, 각각 M개 팀
k 배수, D 경기수 제한

다른 지역리그 팀과 x번 경기
같은 지역리그 팀과 kx번 경기한다면
한 팀당 경기수는 (N-1)*M*x + (M-1)*kx
전체 경기수는 (N(N-1)*M*M*x + N*M*(M-1)*kx) / 2
= NM(NM-M+kM-k)x/2

ex) 2 3 3 60
전체 경기수는 6(6-3+9-3)x/2 = 27x

        */
        int a = N*M*((N*M)-M+(k*M)-k)/2;
        if(D < a) std::cout << "-1\n";
        else {
            // std::cout << "limit = " << D << ", 단위 경기 수 = " << a << '\n';
            std::cout << a * (D/a) << '\n';
        }
    }
}