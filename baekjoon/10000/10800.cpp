#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


const int MAX_N = 200001;
const int MAX_C = 2001;
const int MAX_S = 2001;
int N;


int main(){
    freopen("10800.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    vector< pair<int, pair<int, int> > > a; a.reserve(N + 1);
    a.push_back(make_pair(0, make_pair(0, 0)));

    for(int i = 0; i < N; i++){
        int c, s; // color, size;
        scanf("%d %d", &c, &s);
        a.push_back(make_pair(s, make_pair(i, c)));
    }
    sort(a.begin(), a.end());

    int cnt = 0, total = 0;
    vi sum(N + 1);
    vi color(N + 1);
    vi size(N + 1);
    vi ans(N + 1);

    for(int i = 1; i <= N; i++){
        // 이전 공과 크기가 다르면 sum배열을 업데이트한다.
        if(a[i].first != a[i - 1].first){
            for(int j = 1; j <= cnt; j++){
                sum[color[j]] += size[j];
                total += size[j];
            }
            cnt = 0;
        }
        cnt++;
        size[cnt] = a[i].first;
        color[cnt] = a[i].second.second;

        // 전체 크기에서 동일한 색깔의 공을 제외한다.
        ans[a[i].second.first] = total - sum[a[i].second.second];
    }
    for(int i = 0; i < N; i++){
        printf("%d\n", ans[i]);
    }
}