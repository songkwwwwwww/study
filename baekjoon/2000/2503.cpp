#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <stack>
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

#include <map>
//#include <unordered_map> // c++11

#include <utility> // std::pair

#include <functional> // greater, less
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 100;

struct game{
    int n, s, b;
};

game games[100];

int main(){
    freopen("2503.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &games[i].n, &games[i].s, &games[i].b);
    }
    vb check(1001);
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i == j) continue;

            for(int k = 1; k <= 9; k++){
                if(i == k || j == k) continue;
                int n = i * 100 + j * 10 + k;
                check[n] = true;
                
            }
        }
    }

    int a, b, strike, ball;
    for(int i = 123; i <= 987; i++){
        if(check[i] == false) continue;

        for(int j = 0; j < N; j++){
            strike = 0, ball = 0;
            a = i;
            b = games[j].n;
            for(int k = 0; k < 3; k++){
                if((a % 10) == (b % 10))
                    strike++;
                a /= 10;
                b /= 10;
            }
            if(strike != games[j].s){
                check[i] = false;
                break;
            }
            a = i;
            b = games[j].n;
            // b의 일의 자리의 수가 a의 백의 자리나 십의 자리의 수와 같은가?
            if( ((b % 10) == (a / 100)) || ( (b % 10) == ( (a / 10) % 10 ) ) )
                ball++;
            
            // b의 십의 자리의 수가 a의 백의 자리나 일의 자리의 수와 같은가?
            if((((b / 10) % 10) == (a / 100)) || ( ((b / 10) % 10) == (a % 10)))
                ball++;
            
            // b의 백의 자리의 수가 a의 십의 자리나 일의 자리의 수와 같은가?
            if( ( (b / 100) == ((a/10) % 10) ) || ( (b / 100) == (a % 10) ) )
                ball++;

            if(ball != games[j].b){
                check[i] = false;
                break;
            }
        }
    }
    int ans = 0;
    vi v;
    for(int i = 100; i <= 999; i++){
        if(check[i]){
            ans++;
            v.push_back(i);
        }
    }
    printf("%d\n", ans);
    //for(int i = 0; i < v.size(); i++)
        //printf("%d\n", v[i]);
}