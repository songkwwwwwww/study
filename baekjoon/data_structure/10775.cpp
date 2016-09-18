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


const int MAX_G = 100000;
const int MAX_P = 100000;
int G, P;
int p[MAX_G + 1];

int find(int n){
	if(p[n] < 0) return n;
	else return p[n] = find(p[n]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	p[b] = a;
}

int main(){
    freopen("10775.txt", "r", stdin);
    scanf("%d %d", &G, &P);
    int result = 0;
    memset(p, -1 ,sizeof(p));
    for(int i = 0; i < P; i++){
        int g, root;
        scanf("%d", &g);

        root = find(g);
        if(root > 0){
            result++;
            merge(root - 1, root);
        }
        else 
            break;
    }
    printf("%d\n", result);
}