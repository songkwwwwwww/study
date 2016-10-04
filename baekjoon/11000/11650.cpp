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
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/


int main(){
    freopen("11650.txt", "r", stdin);
    int N; scanf("%d", &N);// 1 <= N <= 10,0000
    vector<pair<int, int> > v;
    v.reserve(N);
    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair (a, b));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }    
}