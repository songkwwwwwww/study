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

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

struct qInstance{
	int key, r, c;
	qInstance():qInstance(0, 0, 0){}
	qInstance(int key1, int r1, int c1):key(key1), r(r1), c(c1){}
};

const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
    freopen("1194.txt", "r", stdin);
	int N, M;
	char map[50][50];
	int sr, sc;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++){
			map[i][j] = getchar();
			if(map[i][j] == '0'){
				sr = i;
				sc = j;
			}
		}
	}

	bool visited[128][50][50] = {0};
	visited[0][sr][sc] = true;
	queue<qInstance> Q;
	Q.push(qInstance(0, sr, sc));
	int result = 0;
	bool success = false;

	while(!Q.empty()){
		int qSize = Q.size();

		for(int i=0; i<qSize; i++){
			int key = Q.front().key;
			int r = Q.front().r;
			int c = Q.front().c;
			Q.pop();
			if(map[r][c] == '1'){
				success = true;
				break;
			}

			for(int d=0; d<4; d++){
				int nkey = key;
				int nr = r + roff[d];
				int nc = c + coff[d];
				if(nr<0 || nr>=N || nc<0 || nc>=M) continue;

				if(map[nr][nc] == '#') continue;
				else if(islower(map[nr][nc])) nkey |= (1 << (map[nr][nc]-'a'));
				else if(isupper(map[nr][nc]))
					if( !(nkey & (1 << (map[nr][nc]-'A'))) ) continue;

				if(visited[nkey][nr][nc]) continue;
				visited[nkey][nr][nc] = true;
				Q.push(qInstance(nkey, nr, nc));
			}
		}

		if(success) break;
		result++;
	}

	if(success) printf("%d\n", result);
	else puts("-1");
}

/*
const int MAX_N = 50;
const int MAX_M = 50;
int N, M;
char m[MAX_N][MAX_M];
bool visited[1 << 6][MAX_N][MAX_M];

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

int main(){
    freopen("1194.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    int sx, sy, ex, ey;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %c", &m[i][j]);
            if(m[i][j] == '0'){
                sx = i;
                sy = j;
            }
            else if(m[i][j] == '1'){
                ex = i;
                ey = j;
            }
        }
    }
    
    queue< pair< pair<int, int>, int > > q;
    q.push(make_pair( make_pair(sx, sy), 0));

    visited[sx][sy][0] = true;;    

    int step = 0;
    bool flag = false;
    
    while(!q.empty()){
        int q_size = q.size();

        for(int i = 0; i < q_size; i++){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int key = q.front().second;
            q.pop();
            
            if(x == ex && y == ey){
                flag = true;
                break;
            }

            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                int nkey = key;

                if(!is_range(nx, ny)) continue;

                if(m[nx][ny] == '#') continue;
                else if('a' <= m[nx][ny] && m[nx][ny] <= 'f'){
                    nkey |= (1 << (m[nx][ny] - 'a'));
                }
                else if('A' <= m[nx][ny] && m[nx][ny] <= 'F'){
                    if( !( nkey & (1 << (m[nx][ny] - 'A')))) continue;
                } 
                if(visited[nx][ny][nkey]) continue;


                visited[nx][ny][nkey] = true;
                q.push(make_pair( make_pair(nx, ny) , nkey));
            }
        }
        if(flag) break;
        step++;
    } // end of while

    if(flag) printf("%d\n", step);
    else printf("-1\n");
}
*/