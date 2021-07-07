#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>

#define FASTIO
// #define DEBUG

const double PI = acos(-1);
typedef std::complex<double> cpx;

void FFT(std::vector<cpx> &a, bool invert)
{
    int n = a.size();
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) std::swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*PI/len*(invert?-1:1);
        cpx wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            cpx w(1, 0);
            for (int j=0;j<len/2;j++){
                cpx u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}

void multiply(const std::vector<int> &a,const std::vector<int> &b, std::vector<int> &res)
{
    std::vector<cpx> fa(a.begin(), a.end());
    std::vector<cpx> fb(b.begin(), b.end());
    int n = 1;
    while (n < std::max(a.size(),b.size())) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

int main() {
    #ifdef FASTIO
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    #endif
    int n;
    std::vector<int> vec_x, vec_y;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        int x_elem;
        std::cin >> x_elem;
        vec_x.push_back(x_elem);
    }
    for(int i=0; i<n; i++) {
        int y_elem;
        std::cin >> y_elem;
        vec_y.push_back(y_elem);
    }
    std::reverse(vec_y.begin(), vec_y.end());
    for(int i=0; i<n; i++) {
        vec_x.push_back(vec_x[i]);
        vec_y.push_back(0);
    }
    std::vector<int> ans;
    multiply(vec_x, vec_y, ans);
    #ifdef DEBUG
    for(const auto &item : ans) {
        std::cout << item << '\n';
    }
    #endif
    int max_conv = -1;
    for(int i=n-1; i<=2*n-2; i++) {
        max_conv = std::max(max_conv, ans[i]);
    }
    std::cout << max_conv << '\n';
}