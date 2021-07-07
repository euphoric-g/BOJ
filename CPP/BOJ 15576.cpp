#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <algorithm>

#define FASTIO
#define DEBUG

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
    FFT(fa,false);
    FFT(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    FFT(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

int main() {
    #ifdef FASTIO
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    #endif
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::vector<int> a, b, ans;
    for(const auto &ch : s1) a.push_back(ch - '0');
    for(const auto &ch : s2) b.push_back(ch - '0');
    multiply(a, b, ans);
    #ifdef DEBUG
    std::cout << "A = ";
    for(const auto &item : a) {
        std::cout << item << ' ';
    }
    std::cout << "\nB = ";
    for(const auto &item : b) {
        std::cout << item << ' ';
    }
    std::cout << "\nANS = ";
    for(const auto &item : ans) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
    #endif

}