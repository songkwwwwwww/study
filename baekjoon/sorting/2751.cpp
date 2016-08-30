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

int a[1000000];
int b[1000000];

// range : [start, end]
void merge(int start, int end){
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;
    while(i <= mid && j <= end){
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= end) b[k++] = a[j++];
    for(int i = start; i <= end; i++)
        a[i] = b[i - start];
}

// range : [start, end]
void merge_sort(int start, int end){
    if(start == end) return ;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, end); 
}

int main(){
    freopen("2751.txt", "r", stdin);
    int N; // 1 <= N <= 100,0000
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    merge_sort(0, N - 1);
    for(int i = 0; i < N; i++) printf("%d ", a[i]);
    printf("\n");
    
}