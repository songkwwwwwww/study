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

const int dx[4] = { 0, 0, 1, -1 }; // E W S N;
const int dy[4] = { 1, -1, 0, 0 }; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_SIZE = 1024;
const int MAX_D = 50;
const int MAX_N = 20000;
int D, N;

int m[MAX_SIZE + 3][MAX_SIZE + 3];


inline bool is_range(int x, int y) {
	return (0 <= x && x < MAX_SIZE && 0 <= y && y < MAX_SIZE);
}

int main() {
	freopen("7536.txt", "r", stdin);
	//setbuf(stdout, NULL);
	int TC, x, y, z;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d %d", &D, &N);
		for (int l = 0; l < N; l++) {
			scanf("%d %d %d", &x, &y, &z);
			for (int i = -D; i <= D; i++) {
				for (int j = -D; j <= D; j++) {
					int nx = x + i;
					int ny = y + j;
					if (0 <= nx && nx <= MAX_SIZE && 0 <= ny && ny <= MAX_SIZE) {
						m[nx][ny] += z;
					}
				}
			}
		}
		int a, b, c;
		a = b = 0;
		c = m[a][b];
		for (int i = 0; i <= MAX_SIZE; i++) {
			for (int j = 0; j <= MAX_SIZE; j++) {
				if (c < m[i][j]) {
					a = i;
					b = j;
					c = m[i][j];
				}
				m[i][j] = 0;
			}
		}
		printf("%d %d %d\n", a, b, c);
	}
}
