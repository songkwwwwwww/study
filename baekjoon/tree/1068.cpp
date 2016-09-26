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
첫째 줄에 트리의 노드의 개수 N이 주어진다. 
N은 50보다 작거나 같은 자연수이다. 

둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다. 
만약 부모가 없다면 (루트) -1이 주어진다. 

셋째 줄에는 지울 노드의 번호가 주어진다.

출력
첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.
*/


const int MAX_N = 50; // [1, 50]
int N, root, target;
vi children[MAX_N];
vi p, count_of_children;
vb deleted;

void delete_node(int here){
    deleted[here] = true;
    if(p[here] != -1)
        count_of_children[p[here]]--;
    
    for(int i = 0; i < children[here].size(); i++){
        int there = children[here][i];
        delete_node(there);
    }
    //children[here].clear();
}



int main(){
    freopen("1068.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    deleted = vb(N);
    count_of_children = vi(N);
    p = vi(N, -1);
    for(int parent, i = 0; i < N; i++){
        scanf("%d", &parent);
        //if(parent == -1) root = i;
        //else children[parent].push_back(i);
        if(parent != -1){
            children[parent].push_back(i);        
            count_of_children[parent]++;
            p[i] = parent;
        }
    }
    scanf("%d", &target);
    delete_node(target);
    int count = 0;
    for(int i = 0; i < N; i++){
        if(!deleted[i] && count_of_children[i] == 0)
            count++;
    }
    printf("%d\n", count);
}