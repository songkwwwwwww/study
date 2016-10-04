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
//#include <unordered_map>

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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;
const int MAX_V = 20000;

/*

*/
const int MAX_N = 2000;
int N, M;
vector<pair<int, int> > vec;




int main(){
    freopen("1615.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    
    vec.reserve(N * (N - 1) / 2 + 1);
    for(int u, v, i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        vec.push_back(make_pair(u, v));
    }
    sort(vec.begin(), vec.end());
    int n = vec.size();
    /*
    for(int i = 0; i < vec.size(); i++){
        cout <<vec[i].first <<" "<<vec[i].second << endl;
    }*/
    int d[2000] = {0};
    for(int i = 0; i < n; i++){
        d[i] = 1;
        for(int j = 0; j < i; j++){
            if(vec[j].second < vec[i].second && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i< n; i++)
        ans = MAX(ans, d[i]);
    printf("%d\n", M - ans);
}