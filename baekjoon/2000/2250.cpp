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
입력
첫째 줄에 노드의 개수를 나타내는 정수 N(1 ≤ N ≤ 10,000)이 주어진다. 
다음 N개의 줄에는 각 줄마다 노드 번호와 해당 노드의 왼쪽 자식 노드와 오른쪽 자식 노드의 번호가 순서대로 주어진다. 
노드들의 번호는 1부터 N까지이며, 자식이 없는 경우에는 자식 노드의 번호에 -1이 주어진다.

출력
첫째 줄에 너비가 가장 넓은 레벨과 그 레벨의 너비를 순서대로 출력한다. 
너비가 가장 넓은 레벨이 두 개 이상 있을 때에는 번호가 작은 레벨을 출력한다.
*/

const int MAX_N = 10000;
int N;

vi p;
vi left_child, right_child;
vi left_most, right_most;


int calc(int here, int jump, int level){
    int count = 0;
    if(left_child[here] != -1)
        count += calc(left_child[here], jump, level + 1);
    
    left_most[level] = min(left_most[level], jump + count);
    right_most[level] = max(right_most[level], jump + count);
    count++;

    if(right_child[here] != -1)
        count += calc(right_child[here], jump + count, level + 1);
    return count;
}

int main(){
    freopen("2250.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    // init
    left_child = vi(N, -1); right_child = vi(N, -1);
    left_most = vi(N, INF); right_most = vi(N, -1);
    p = vi(N, -1);

    for(int n, l, r, i = 0; i < N; i++){
        scanf("%d %d %d", &n, &l, &r);
        if(l != -1){
            left_child[n - 1] = l - 1;
            p[l - 1] = n - 1;
        }
        
        if(r != -1){
            right_child[n - 1] = r - 1;
            p[r - 1] = n - 1;
        }
    }
    int root;
    for(int i = 0; i < N; i++){
        if(p[i] == -1){
            root = i;
            break;
        }
    }
    calc(root, 0, 0);

    int result_width = 0, result_level = 0;
    for(int i = 0; i < N; i++){
        if(left_most[i] == INF) break;
        if(result_width < right_most[i] - left_most[i]){
            result_width = right_most[i] - left_most[i];
            result_level = i;
        }
    }
    printf("%d %d\n", result_level + 1, result_width + 1);
}