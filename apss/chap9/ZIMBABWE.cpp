#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi

#include <cstdio>
#include <cstring>
#include <cmath> // std::abs

using namespace std;
typedef long long ll;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

const int MOD = 1000000007;

int TC; // TC <= 50

// 현재 계란 가격 e, 사탕 m개
string e; // 1 <= e <= 10^14
int n, m; // 2 <= m <= 20

// digits : e의 자릿수들을 정렬한 것
string digits;
int cache[1 << 14][20][2];

//과거 가격을 앞 자리부터 채워나가고 있다.
// index: 이번에 채울 자리의 인덱스
int price(int index, int taken, int mod, int less){
    // base case
    if(index == n) return (less && mod == 0) ? 1 : 0;
    // memoization
    int& ret = cache[taken][mod][less];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = 0; next < n; ++next){
        if( (taken & (1 << next)) == 0 ){
            //과거 가격은 새 가격보다 항상 작아야만 한다.
            if(!less && e[index] < digits[next]) continue;
            // 같은 숫자는 한 번만 선택한다.
            if(next > 0 && digits[next - 1] == digits[next] &&
                (taken & (1 << (next - 1))) == 0) continue;
            int next_taken = taken | ( 1 << next);
            int next_mod = (mod * 10 + digits[next] - '0') % m;
            int next_less = less || e[index] > digits[next];
            ret += price(index + 1, next_taken, next_mod, next_less);
            ret %= MOD;
        }
    }
    return ret;
}



// Q. 가능한 이전 계란 가격은 몇 가지인가?
int main(){
    freopen("ZIMBABWE.txt", "r", stdin);

    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        cin >> e >> m;
        memset(cache, -1, sizeof(cache));
        digits = e;
        sort(digits.begin(), digits.end());
        n = e.size();
        printf("%d\n", price(0, 0, 0, 0));
    }
}

/*

// TLE CODE

bool could_it_be_devided(string& s, int m){
    int mod = 0;
    for(int i = 0; i < s.size(); i++){
        mod = ((mod * 10) + (s[i] - '0')) % m;
    }
    return mod == 0 ? true : false;
}

// Q. 가능한 이전 계란 가격은 몇 가지인가?
int main(){
    freopen("ZIMBABWE.txt", "r", stdin);
    int TC; // TC <= 50
    int m; // 2 <= m <= 20

    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        // 현재 계란 가격 e, 사탕 m개
        string e; // 1 <= e <= 10^14

        cin >> e >> m;
        ll count = 0;
        
        while( prev_permutation(e.begin(), e.end()) ){
            if( could_it_be_devided(e, m) ) count++;
        }
        count %= MOD;
        printf("%lld\n", count);
    }
}


*/