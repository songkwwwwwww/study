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

typedef vector<int> vi;
typedef vector<vi> vvi;

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


const int MAX_N = 10000;


int main(){
    freopen("1826.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, L, P;
    scanf("%d", &N);
    vector<pii> gas_station;
    gas_station.reserve(N);
    //vi gas_station(N + 1), fuel(N + 1);
    for(int i = 0; i < N; i++){
        int p, f;
        scanf("%d %d", &p, &f);
        gas_station.push_back(pii(p, f));
        //scanf("%d %d", &gas_station[i], &fuel[i]);
    }
    scanf("%d %d", &L, &P);
    sort(gas_station.begin(), gas_station.end());
    //gas_station[N] = L;
    //fuel[N] = 0;
    gas_station.push_back(pii(L, 0));
    int cur = 0, ans = 0, tank = P;
    priority_queue<int> pq;
    for(int i = 0; i < N + 1; i++){
        //int distance = gas_station[i] - cur;
        int distance = gas_station[i].first - cur;

        while(tank - distance < 0){
            if(pq.empty()){
                printf("-1\n");
                return 0;
            }

            tank += pq.top(); 
            pq.pop();
            ans++;
        }
        tank -= distance;
        cur = gas_station[i].first;
        if(cur >= L) break;
        pq.push(gas_station[i].second);
        //pq.push(fuel[i]);
    }
    printf("%d\n", ans);
}