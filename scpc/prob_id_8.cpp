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

int ldp[100000], rdp[100000];
int n, data[100000];

int main(){
    freopen("prob_id_8.txt", "r", stdin);
    setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", data + i);
		ldp[0] = 1;
		for(int i = 1; i < n; i++) {
			int cand = ldp[i - 1] + 1;
			ldp[i] = min(cand, data[i]);
		}
		rdp[n - 1] = 1;
		for(int i = n - 2; i >= 0; i--) {
			int cand = rdp[i + 1] + 1;
			rdp[i] = min(cand, data[i]);
		}

		int ans = 0;
		for(int i = 0; i < n; i++) 
            ans = max(ans, min(ldp[i], rdp[i]));
		printf("Case #%d\n%d\n", tc, ans);
    }
}

		