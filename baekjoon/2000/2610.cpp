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


const int MAX_N = 100;

vi p;


int find(int n){
	if(p[n] < 0) return n;
	else return p[n] = find(p[n]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(p[a] < p[b]){
		p[a] += p[b];
		p[b] = a;
	}
	else{ // p[a] > p[b]
		p[b] += p[a];
		p[a] = b;
	}
}

int main(){
    freopen("2610.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, M;
    scanf("%d %d", &N, &M);
    
    vvi dist(N, vi(N, INF));
    for(int i = 0; i < N; i++) dist[i][i] = 0;
    
    p = vi(N, -1);

    for(int i = 0; i < M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        dist[u][v] = dist[v][u] = 1;
        merge(u, v);
    }

    for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    // 각 집합의 장은 p[a]에 음의 값을 가지고 있는다.(그룹원의 수의 음의 값)
    // 이를 그룹 인덱스로 변경(-1부터 시작하는 인덱싱)
    int K = 0;
    for(int i = 0; i < N; i++)
        if(p[i] < 0)
            p[i] = -(++K);
    
    vi boss(N, INF), size(N, INF);
    for(int i = 0; i < N; i++){
        int max_distance_from_i = 0;
        for(int j = 0; j < N; j++)
            if(dist[i][j] != INF)
                max_distance_from_i = max(max_distance_from_i, dist[i][j]);
        
        int group_num = -p[find(i)] - 1;
        if(size[group_num] > max_distance_from_i){
            size[group_num] = max_distance_from_i;
            boss[group_num] = i + 1;
        }
    }
    sort(boss.begin(), boss.end());
    printf("%d\n", K);
    for(int i = 0; i < K; i++)
        printf("%d\n", boss[i]);
}