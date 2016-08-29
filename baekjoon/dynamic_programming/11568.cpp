#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

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
int N; // 1 <= N <= 1000
int a[1001];
int d[1001];

int main(){
    freopen("11568.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
    int max_value = 1;
    for(int i = 1; i <= N; i++){
        d[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[j] < a[i] && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
                max_value = MAX(max_value, d[i]);
            }
        }
    }
    printf("%d\n", max_value);
}