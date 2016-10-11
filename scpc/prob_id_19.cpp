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

struct val{ 
    int l, r;
	bool operator <(const val& rhs) const{
		return l == rhs.l ? r > rhs.r : l < rhs.l;
	}
};

const int MAX_N = 100000;
const int MAX_VAL = 10000000;
val a[MAX_N];


int main(){
    freopen("prob_id_19.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        int N;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d %d", &a[i].l, &a[i].r);
        }
        sort(a, a + N);
        vi d(N, INF);
        for(int i = 0; i < N; i++){
            *upper_bound(d.begin(), d.end(), a[N - i - 1].r) = a[N - i - 1].r;
        }
        int ans = find(d.begin(), d.end(), INF) - d.begin();
        if(ans == 0) ans = -1;
        printf("Case #%d\n%d\n", tc, ans);
    }
}