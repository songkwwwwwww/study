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
int A[500001];
int main(){
    freopen("1377.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    vector<pair<int, int> > v(N);

    for(int i = 0; i < N; i++){
        scanf("%d", &v[i].first);
        v[i].second = i;
    } 
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        ans = max(v[i].second - i, ans);
    }
    printf("%d\n", ++ans);
}