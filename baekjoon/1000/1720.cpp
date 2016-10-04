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
int d[31];

int main(){
    freopen("1720.txt", "r", stdin);
    int N; // 1 <= N <= 
    scanf("%d", &N);
    d[0] = d[1] = 1;
    for(int i = 2; i <= N; i++)
        d[i] = d[i - 1] + 2 * d[i - 2];
    if(n % 2 == 0){
        printf("%d\n", d[N] - d[N/2]);    
    }
    else{
        printf("%d\n", d[N] - (d[N/2] + 2 * d[N/2 - 1]));    
    }
}