#include <iostream>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::string text;
    std::getline(std::cin, text);
    const std::string happy = ":-)", sad = ":-(";
    int happy_cnt = 0, sad_cnt = 0;
    auto happy_loc = text.find(happy, 0);
    auto sad_loc = text.find(sad, 0);
    while(happy_loc != std::string::npos) {
        happy_cnt++;
        happy_loc = text.find(happy, happy_loc+3);
    }
    while(sad_loc != std::string::npos) {
        sad_cnt++;
        sad_loc = text.find(sad, sad_loc+3);
    }
    std::string result;
    if(sad_cnt == 0 && happy_cnt == 0) {
        result = "none\n";
    } else if(sad_cnt == happy_cnt) {
        result = "unsure\n";
    } else if(sad_cnt > happy_cnt) {
        result = "sad\n";
    } else result = "happy\n";
    std::cout << result;
    return 0;
}