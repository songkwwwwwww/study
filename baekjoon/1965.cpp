#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

const int INF = 987654321;
const int MAX_N = 1000;

/*
입력
파일의 첫 번째 줄은 상자의 개수 n (1≤n ≤1000)을 나타낸다. 두 번째 줄에는 각 상자들의 크기가 순서대로 주어진다.

출력
첫째 줄에 한 줄에 넣을 수 있는 최대의 상자 개수를 출력한다.
*/

int main(){
    freopen("1965.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    vi a(N);
    vi d(N, INF);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    
    for(int i = 0; i < N; i++){
        *lower_bound(d.begin(), d.end(), a[i]) = a[i];
    }
    int ans = find(d.begin(), d.end(), INF) - d.begin();
    printf("%d\n", ans);
}