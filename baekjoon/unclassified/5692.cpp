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

const int MAX_N = 8;
const int MAX_M = 8;

int factorials[6];
int main(){
    freopen("5692.txt", "r", stdin);
    factorials[1] = 1;
    for(int i = 2; i <= 5; i++)
        factorials[i] = factorials[i - 1] * i;
    int num;
    while(scanf("%d", &num) && num != 0){
        int sum = 0, p = 1;
        while(num != 0){
            sum += ((num % 10) * factorials[p++]);
            num /= 10;
        }
        printf("%d\n", sum);
    }
}