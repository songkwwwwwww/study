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
세그먼트 트리를 이용해서 해결할 수 있다.
각 노드는 연결된 선분의 집합에 대응해 다음과 같은 정보를 가진다.

대응한 선분들을 최초의 선분을 수직으로 해서 연결했을 때의 
최초 선분의 끝점에서 최후의 선분의 끝점까지의 벡터

(그 노드가 자식 노드를 가진다면) 2개의 자식 노드에 대응하는 부분을 연결할 때
오른쪽 자식 노드의 부분을 회전시킨 각도 
*/
const int MAX_N = 10000;
const int MAX_C = 10000;

const int ST_SIZE = (1 << 15) - 1;

// 입력
int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_N];

// 세그먼트 트리 데이터
double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];

// 각도의 변화를 조사하기 위해, 현재의 각도를 보존해준다
double prv[MAX_N];

// 세그먼트 트리를 초기화한다
// k는 노드 번호, l, r은 그 노드가 [l, r) 에 대응해 있다는 것을 나타낸다
void init(int k, int l, int r){
    ang[k] = vx[k] = 0.0;

    if(l + 1 == r){
        // 노드
        vy[k] = L[l];
    }
    else{
        // 노드가 아닌 절점
        int chl = k * 2 + 1, chr = k * 2 + 2;
        init(chl, l, (l + r) / 2);
        init(chl, (l + r) / 2, r);
        vy[k] = vy[chl] + vy[chr];        
    }
}

// 장소 s의 각도가 a만 변경된다.
// v는 노드의 번호, l, r은 그 노드가 [l, r) 에 대응되고 있다는 것을 나타낸다
void change(int s, double a, int v, int l, int r){
    if(s <= l) return;
    else if(s < r){
        int chl = v * 2 + 1, chr = v * 2 + 2;
        int m = (l + r) / 2;
        change(s, a, chl, l, m);
        change(s, a, chr, m, r);
        if(s <= m) ang[v] += a;

        double s = sin(ang[v]), c = cos(ang[v]);
        vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr]);
        vy[v] = vy[chl] + (s * vx[chr] + s * vy[chr]);
    }
}

int solve(){
    // 초기화
    init(0, 0, N);
    for(int i = 1; i < N; i++) prv[i] = M_PI;

    // 각 쿼리를 처리
    for(int i = 0; i < C; i++){
        int s = S[i];
        double a = A[i] / 360.0 * 2 * M_PI;

        change(s, a - prv[s], 0, 0, N);
        prv[s] = a;

        printf("%.2f %.2f\n", vx[0], vy[0]);
    }
}

int main(){
    freopen("6661.txt", "r", stdin);
    //setbuf(stdout, NULL);
    
    while(scanf("%d %d", &N, &C) == 2){
        for(int i = 0; i < N; i++)
            scanf("%d", &L[i]);
        for(int i = 0; i < C; i++){
            scanf("%d %d", &S[i], &A[i]);
        }
        solve();
        printf("\n");
    }
}