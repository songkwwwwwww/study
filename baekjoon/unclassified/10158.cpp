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

const int dx[4] = {-1, -1, 1, 1}; // NE NW SE SW;
const int dy[4] = {1, -1, 1, -1}; // NE NW SE SW;

const int INF = 987654321;

/*
입력
첫줄에는 w와 h가 공백을 사이에 두고 주어진다. 
그 다음 줄에는 초기 위치의 좌표값 p와 q가 공백을 사이에 두고 주어진다. 
3번째 줄에는 개미가 움직일 시간 t가 주어진다. 

출력
출력은 t 시간 후에 개미의 위치 좌표 (x,y)의 값 x와 y를 공백을 사이에 두고 출력한다.
*/



int main(){
    freopen("10158.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int w, h, t, px, py;
    int d = 0;
    scanf("%d %d %d %d %d", &w, &h, &px, &py, &t);
    int x = (px + t) % w;
    int y = (py + t) % h;
    
    if(((px + t) / w) & 1) px = w - ((px + t) % w);
    else px = ((px + t) % w);

    if(((py + t) / h) & 1) py = h - ((py + t) % h);
    else py = ((py + t) % h);

    printf("%d %d\n", px, py);
}