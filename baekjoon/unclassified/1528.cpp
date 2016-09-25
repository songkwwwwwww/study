#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <stack>
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>
#include <sstream>
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


const int MAX_N = 1000000;
 
int main(){
    freopen("1528.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);

    qi q; q.push(4); q.push(7); 
    vi v; v.reserve(10000); v.push_back(4); v.push_back(7);
    while(!q.empty()){
        int here = q.front(); q.pop();
        if(here * 10 + 4 <= N){
            q.push(here * 10 + 4); v.push_back(here * 10 + 4);
        }
        if(here * 10 + 7 <= N){
            q.push(here * 10 + 7); v.push_back(here * 10 + 7);
        }
    }

    vi track(N + 1, -1);
    q.push(0);
    while (!q.empty()){
        int here = q.front(); q.pop();  
        if (here == N) break;

        for (int i = 0; i < v.size(); i++){
            int there = here + v[i]; 
            if (there <= N && track[there] == -1){
                track[there] = here; 
                q.push(there); 
            }
        }
    }
    if (track[N] == -1) printf("-1\n"); 
    else{
        vi result;
        for(int t = N ; t != -1; t = track[t])
            result.push_back(t - track[t]); 
        
        int size = result.size();
        //printf("size : %d\n", size);
        for(int i = size - 2; i >= 0; i--){
            printf("%d ", result[i]);
        }
        printf("\n");
        /*
        for(int i = 0; i < result.size(); i++){
            printf("%d ", result[i]);
        }
        printf("\n");*/
        
    }    
}