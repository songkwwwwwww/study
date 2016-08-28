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


int p[101];

int Find(int x){
    if(x == p[x]){
        return x;
    }
    else{
        return p[x] = Find(p[x]);
    }
}

int Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if( x != y) p[y] = x;
}

int main(){
    freopen("2606.txt", "r", stdin);
    int n_of_com, n_of_connect;
    scanf("%d %d", &n_of_com, &n_of_connect);
    for(int i = 1; i <= n_of_com; i++) p[i] = i;
    for(int i = 0; i < n_of_connect; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        Union(a, b);
    }
    int count = 0;
    int target = Find(1);
    for(int i = 2; i <= n_of_com; i++)
        if(target == Find(i))
            count++;
    printf("%d\n", count);
}