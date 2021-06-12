#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int hp, mp, atk, def, hpd, mpd, atkd, defd;
        std::cin >> hp >> mp >> atk >> def >> hpd >> mpd >> atkd >> defd;
        int power = 1*(hp+hpd < 1 ? 1 : hp+hpd) + 5*(mp+mpd < 1 ? 1 : mp+mpd) + 2*(atk+atkd < 0 ? 0 : atk+atkd) + 2*(def+defd);
        std::cout << power << '\n';
    }
    return 0;
}