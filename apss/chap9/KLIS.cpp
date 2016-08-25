#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi

#include <cstdio>
#include <cstring>
#include <cmath> // std::abs

using namespace std;
typedef long long ll;

//#define MAX(x, y) ((x) > (y) ? (x) : (y))
//#define MIN(x, y) ((x) < (y) ? (x) : (y))

const int MAX = 0x7fffffff;

// TC <= 50
// 수열에 포함된 원소의 개수 N (N <= 500)
// 주어진 수열의 LIS는 최소 K 개 있다고 가정해도 좋다. 
int TC, N, K;


int cache_len[501], cache_cnt[501], S[500];

int lis(int start){
    // 메모이제이션
    int& ret = cache_len[start + 1];
    if(ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    for(int next = start + 1; next < N; next++)
        if(start == -1 || S[start] < S[next])
            ret = max(ret, lis(next) + 1);
    return ret;
}

// S[start] 에서 시작하는 최대 증가 부분 수열의 수를 반환한다.
int count(int start){       
    // base case
    if(lis(start) == 1) return 1;
    // 메모이제이션
    int& ret = cache_cnt[start + 1];
    if(ret != -1) return ret;    
    ret = 0;
    for(int next = start + 1; next < N; next++){
        if( (start == -1 || S[start] < S[next]) &&
            lis(start) == lis(next) + 1 )
            ret = min<long long>(MAX, (long long)ret + count(next));
    }
    return ret;
}

// S[start]에서 시작하는 LIS 중 사전순으로 skip개 건너뛴 수열을
// lis에 저장한다.
void reconstruct(int start, int skip, vector<int>& ans){
    // 1. S[start]는 항상 LIS에 포함된다.
    if(start != -1) ans.push_back(S[start]);

    // 2. 뒤에 올 수 있는 숫자들과 위치의 목록을 만든다.
    // (숫자, 숫자의 위치) 의 목록이 된다.
    vector<pair<int, int> > followers;
    for(int next = start + 1; next < N; next++)
        if( (start == -1 || S[start] < S[next]) &&
            lis(start) == lis(next) + 1)
            followers.push_back(make_pair(S[next], next));
    sort(followers.begin(), followers.end());
    // 3. k번쨰 LIS의 다음 숫자를 찾는다.
    for(int i = 0; i < followers.size(); i++){
        // 이 숫자를 뒤에 이어서 만들 수 있는 LIS의 개수를 본다.
        int idx = followers[i].second;
        int cnt = count(idx);
        if(cnt <= skip) skip -= cnt;
        else{
            // 다음 숫자는 S[idx]임을 알았다.
            // 4. 재귀 호출을 통해
            reconstruct(idx, skip, ans);
            break;
        }
    }
}

// 모든 숫자가 서로 다른 (중복 숫자가 없는) 수열이 주어질 때, 
// 이 수열의 LIS 중 사전 순서대로 맨 앞에서 k번째 있는 LIS 를 출력
int main(){
    freopen("KLIS.txt", "r", stdin);
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d %d", &N, &K);
        for(int i = 0; i < N; i++) scanf("%d", &S[i]);

        memset(cache_len, -1, sizeof(cache_len));
        memset(cache_cnt, -1, sizeof(cache_cnt));
        
        vector<int> v;
        reconstruct(-1, K-1, v);

        printf("%d\n", v.size());
        for(int i = 0; i < v.size(); i++)
            printf("%d ", v[i]);
        printf("\n");
    }
}