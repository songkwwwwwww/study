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


const int MAX_N = 1000;
const int MAX_M = 50;
int N, M;
char str[MAX_N][MAX_M + 1];


// A C G T
int main(){
    freopen("1969.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", str[i]);
    char result[MAX_M + 1];
    int p = 0;
    int sum = 0;
    for(int i = 0; i < M; i++){
        vi text_score(26);
        for(int j = 0; j < N; j++){
            text_score[str[j][i] - 'A']++;
        }
        int max_count = 0;
        char max_alpha;
        for(int j = 25; j >= 0; j--){
            if(text_score[j] >= max_count){
                max_count = text_score[j];
                max_alpha = j + 'A';
            }
        }
        sum += (N - max_count);
        result[p] = max_alpha;
        p++;
    }
    result[p] = '\0';
    printf("%s\n%d\n", result, sum);
}