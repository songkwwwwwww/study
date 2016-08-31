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

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/

int triangle[121];
int d[300001];

int main(){
    freopen("1660.txt", "r", stdin);
    int N, num = 0, index;
    scanf("%d", &N);
    for(index = 1; ; index++){
        num += index * (index + 1) / 2;
        if(num >= 300000){
            index--;
            break;
        } 
        triangle[index] = num;
    }
    for(int i = 0; i <= N; i++) d[i] = 987654321;
    
    for(int i = 1; i <= index; i++){
        d[triangle[i]] = 1;
        for(int j = triangle[i]; j <= N; j++){
            d[j] = MIN(d[j], d[j - triangle[i]] + 1);
        }
    }
    printf("%d\n", d[N]);
}