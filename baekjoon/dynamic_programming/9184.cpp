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

int d[21][21][21];
int w(int a, int b, int c){
    // 0 보다 작은 수는 여기서 걸러진다
    if(a <= 0 || b <= 0 || c <= 0) 
        return 1;

    // 20 보다 큰 수는 여기서 걸러진다.
    if( a > 20 || b > 20 || c > 20) 
        return w(20, 20, 20);
    
    int& ret = d[a][b][c];
    if(ret != -1) return ret;
    
    
    if(a < b && b < c) 
        return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    
    else
        return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(){
    freopen("9184.txt", "r", stdin);
    
    memset(d, -1, sizeof(d));
    int a, b, c;
    while(true){
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}