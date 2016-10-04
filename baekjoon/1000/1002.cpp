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
    freopen("1002.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int d_square = pow(x1 - x2, 2) + pow(y1 - y2, 2);
        int r_square = pow(r1 + r2, 2);

        if(d_square > r_square) printf("0\n");
        else if(d_square == r_square) printf("1\n");
        else{ // r_square > d_square
            int r_diff_square = pow(r1 - r2, 2);
            if(d_square == 0 && r_diff_square == 0) printf("-1\n");
            else if(r_diff_square == d_square) printf("1\n");
            else if( d_square > r_diff_square ) printf("2\n");
            else printf("0\n");
        }
    }
}