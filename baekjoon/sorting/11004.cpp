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
    http://www.sourcetricks.com/2011/06/quick-select.html#.V8Yq7yiLTIU
*/
int a[5000000];

int partition(int l, int r)
{
    int pivot = a[r];
    while ( l < r ){
        while ( a[l] < pivot )
            l++;
        while ( a[r] > pivot )
            r--;
        if ( a[l] == a[r] )
            l++;
        else if ( l < r ) {
            int tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
        }
    }
    return r;
}


int quick_select(int left, int right, int k){
    if ( left == right ) return a[left];
    int j = partition(left, right);
    int length = j - left + 1;
    if ( length == k ) return a[j];
    else if ( k < length ) return quick_select(left, j - 1, k);
    else  return quick_select(j + 1, right, k - length);
}

int main(){
    freopen("11004.txt", "r", stdin);
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    printf("%d\n", quick_select(0, N - 1, K));
}