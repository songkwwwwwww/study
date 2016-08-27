#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;
vector<char> alpha;
bool check(string& pw){
    int ja = 0;
    int mo = 0;
    for(int i = 0; i < pw.size(); i++){
        if(pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u'){
            mo++;
        }
        else{
            ja++;
        }
    }
    return (ja >= 2 && mo >= 1);
}

void go(int n, int i, string pw){
    if(pw.length() == n){
        if(check(pw)){
            cout << pw << endl;
        }
        return ;
    }
    if(i >= alpha.size()) return;
    go(n, i + 1, pw + alpha[i]);
    go(n, i + 1, pw);
}

int main(){
    freopen("1759.txt", "r", stdin);
    // 서로 다른 L 개의 알파벳 소문자.
    // 암호로 사용했을 법한 문자의 종류는 C 가지
    // 3 <= L <= C <= 15
    int L, C;
    scanf("%d %d", &L, &C);
    alpha.reserve(C);
    for(int i = 0; i < C; i++){
        char c;
        cin >> c;
        alpha.push_back(c);
    }
    sort(alpha.begin(), alpha.end());
    go(L, 0, "");
}