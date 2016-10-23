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

// 초밥의 종류 n ( 1 <= n <= 20)
// 운영진들의 예산 m ( 1 <= m <= 2,147,483,647 )
int n, m;

int prices[20];
int preferences[20];

int d[201];

int calc(){
    int ret = 0;
    d[0] = 0;
    for(int budget = 1; budget <= m; budget++){
        int cand = 0;
        for(int dish = 0; dish < n; dish++){
            if(budget >= prices[dish]){
                cand = max(cand, d[(budget - prices[dish]) % 201]
                    + preferences[dish]);
            }
        }
        d[budget % 201] = cand;
        ret = max(ret, cand);
    }
    return ret;
}

int main(){
    freopen("SUSHI.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d %d", &n, &m);
        m /= 100;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &prices[i], &preferences[i]);
            prices[i] /= 100;
        }
        cout<< calc() << endl;
    }
}