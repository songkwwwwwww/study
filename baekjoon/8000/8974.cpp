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


const int MAX_A = 1000;
const int MAX_B = 1000;

int main(){
    freopen("8974.txt", "r", stdin);
    //setbuf(stdout, NULL);
    vi v;
    v.reserve(1001 * 1000 / 2);
    for(int i = 1; i <= 1000; i++){
        for(int j = 0; j < i; j++){
            v.push_back(i);
        }
    }
    int A, B;
    scanf("%d %d", &A, &B);
    int sum = 0;
    for(int i = A; i <= B; i++){
        sum += v[i - 1];
    }
    printf("%d\n", sum);
}