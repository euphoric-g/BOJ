#include <cstdio>

int main() {
    int t, h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    t = -h*60*60-m*60-s;
    scanf("%d:%d:%d", &h, &m, &s);
    t += h*60*60+m*60+s;
    if(t < 0) t += 24*60*60;
    h = t / (60*60);
    m = (t % (60*60)) / 60;
    s = t % 60;
    printf("%s%d:%s%d:%s%d\n", h/10?"":"0", h, m/10?"":"0", m, s/10?"":"0", s);
}