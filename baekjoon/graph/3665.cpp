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


const int MAX_N = 500;
const int MAX_M = 25000;
vvi adj;

int main(){
    freopen("3665.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        int N, M;
        scanf("%d", &N);
        //adj = vvi(N + 1, vi(N + 1));
        vi adj[N];
        vi people(N); // 사람 i의 rank를 보관하는 배열
        vi in_degree(N);
        vvb changed(N, vb(N));
        for(int idx, i = 0; i < N; i++){
            scanf("%d", &idx);
            idx--;
            people[idx] = i;
        }
        scanf("%d", &M);
        // 기본적으로
        // 높은 랭크 사람 -> 낮은 랭크 사람 순으로 그래프를 만든다.

        // 작년의 순위와 뒤바뀐 경우
        // 작년의 낮은 랭크였던 사람 -> 높은 랭크였던 사람 순으로 이어주고 체크한다. 
        for(int i = 0; i < M; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            a--; b--;
            if(people[a] > people[b]) swap(a, b);
            adj[b].push_back(a);
            in_degree[a]++;
            changed[a][b] = true;
        }

        // 위에서 체크한 것을 제외하고
        // 작년 순위에 기반하여
        // 높은 랭크 사람-> 낮은 랭크 사람
        // 순으로 이어준다.
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i == j) continue;
                if(people[i] < people[j] && !changed[i][j]){
                    adj[i].push_back(j);
                    in_degree[j]++;
                }
            }
        }

        qi q;
        for(int i = 0; i < N; i++)
            if(in_degree[i] == 0)
                q.push(i);
        
        bool impossible = false, ambiguous = false;
        vi result(N);
        
        for(int k = 0; k < N; k++){
            if(q.empty()){
				impossible = true;
				break;
			}
			if(q.size() > 1) ambiguous = true;

			int here = q.front(); q.pop();
			result[k] = here;
			for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i];
				if(--in_degree[there] == 0) 
                    q.push(there);
            }
        }
        if(impossible) puts("IMPOSSIBLE");
		else if(ambiguous) puts("?");
		else{
			for(int i = 0; i < N; i++)
				printf("%d ", result[i]+1);
			puts("");
		}
        /*
        for(int i = 0; i < N; i++)
            printf("%d ", people[i]);
            printf("\n");
        */
    }
}