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
int num_count[10001];
int main(){
    freopen("10989.txt", "r", stdin);
    int N, num;
    scanf("%d", &N);
    //memset(num_count, 0, sizeof(num_count));
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        num_count[num]++;
    }
    for(int i = 1; i <= 10000; i++)
        if(num_count[i] != 0)
            for(int j = 1; j <= num_count[i]; j++)
                printf("%d\n", i);
}