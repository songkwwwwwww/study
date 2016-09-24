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


const int MAX_R = 1000;
const int MAX_N = 1000;
int a[MAX_N];

int main(){
    freopen("3069.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int R, N;
    while(scanf("%d %d", &R, &N) && R != -1 && N != -1){
        for(int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        
        sort(a, a + N);

        int ans = 0, i = 0;
        while(i < N){
            // l는 커버되지 않은 가장 왼쪽 점의 위치
            int l = a[i++];

            while(i < N && a[i] <= l + R) i++;

            // p는 새롭게 찍을 점의 위치
            int p = a[i - 1];
            
            while(i < N && a[i] <= p + R) i++;
            ans++;
        }
        printf("%d\n", ans);
    }
}