// 10757
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>

// 첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)
//
const int MAX_N = 10000;

int main(){
#ifdef SONG_INPUT
    freopen("input.txt", "r", stdin);
#endif
#ifdef SONG_TEST
#endif
    std::string a, b;
    char c[MAX_N + 3];
    a.reserve(MAX_N + 3);
    b.reserve(MAX_N + 3);

    std::cin >> a >> b;

    int max_len = std::max(a.size(), b.size());
    int min_len = std::min(a.size(), b.size());
    
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int i = 0, carry = 0;
    for(; i < max_len; i++) {
        int lhs = i < a.size() ? (a[i] - '0') : 0;
        int rhs = i < b.size() ? (b[i] - '0') : 0;
        int current = lhs + rhs + carry;
        carry = current / 10;
        c[i] = (current % 10) + '0';
    }

    if (carry != 0) {
        c[i++] = carry + '0';
    }

    std::reverse(c, c + i);
    c[i] = 0;
    std::cout <<  c << std::endl;
}