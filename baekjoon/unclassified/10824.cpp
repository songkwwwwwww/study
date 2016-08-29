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
int main(){
    freopen("10824.txt", "r", stdin);
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    ll AB, CD;
    ll carry = 1;
    int b = B;
    while(b){
        b /= 10;
        carry *= 10;
    }
    AB = (ll)A * carry + B;
    
    carry = 1;
    int d = D;
    while(d){
        d /= 10;
        carry *= 10;
    }
    CD = (ll)C * carry + D;
    printf("%lld\n", AB + CD);
}