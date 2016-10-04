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

const int INF = 987654321;
const int MAX_V = 20000;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
첫째 줄에 미로의 크기를 나타내는 가로 크기 M, 세로 크기 N (1 ≤ N, M ≤ 100)이 주어진다. 
다음 N개의 줄에는 미로의 상태를 나타내는 숫자 0과 1이 주어진다. 0은 빈 방을 의미하고, 1을 벽을 의미한다.

(1, 1)과 (N, M)은 항상 뚫려있다.

출력
첫째 줄에 알고스팟 운영진이 (N, M)으로 이동하기 위해 벽을 최소 몇 개 부수어야 하는지 출력한다.
*/

int R, C;

inline bool is_range(int x, int y){
	if(0 <= x && x < R && 0 <= y && y < C)
		return true;
	else
		return false;
}
vector< pair<int, int> > adj[10000];

int main(){
    freopen("1261.txt", "r", stdin);
	scanf("%d %d", &C, &R);
	int W[100][100];
	for(int i = 0; i < R; i++){
		char str[101];
		scanf("%s", str);
		for(int j = 0; str[j]; j++){
			W[i][j] = str[j] - '0';
		}
	}
	
	for(int x = 0; x < R; x++){
		for(int y = 0; y < C; y++){
			for(int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(is_range(nx, ny)){
					adj[x * C + y].push_back(make_pair(nx * C + ny, W[nx][ny]));
				}
			}
		}
	}

	vector<int> dist(R * C, INF);
    dist[0] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 0));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = cost + adj[here][i].second;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
	printf("%d\n", dist[R * C - 1]);
}

/*
#include <cstdio>
#include <deque>
using namespace std;
int a[100][100];
int d[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int main(){
	int m, n;
	freopen("1261.txt", "r", stdin);
	scanf("%d %d", &m, &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &a[i][j]);
			d[i][j] = -1;
		}		
	}
	deque<pair<int, int> > q;
	q.push_back(make_pair(0, 0));
	d[0][0] = 0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for(int k = 0; k < 4; k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(0 <= nx && nx < n && 0 <= ny && ny < m){
				if(d[nx][ny] == -1){
					if(a[nx][ny] == 0){
						d[nx][ny] = d[x][y];
						q.push_back(make_pair(x, y));
					}
					else{
						d[nx][ny] = d[x][y] + 1;
						q.push_back(make_pair(nx, ny));						
					}
				}
			}
		}
		
	}
	printf("%d\n", d[n-1][m-1]);
	
}
*/