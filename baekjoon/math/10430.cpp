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
    freopen("10430.txt", "r", stdin);
    int A, B, C; // 2 <= A, B, C <= 10000
    scanf("%d %d %d", &A, &B, &C);
    printf("%d\n",  (A + B) % C);
    printf("%d\n", (A % C + B % C) % C);
    printf("%d\n", (A * B) % C);
    printf("%d\n", ((A % C) * (B % C)) % C );
}