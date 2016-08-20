
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int N;

map<vector<int>, int> to_sort;

void precalc(int n){
    vector<int> perm(n);
    for(int i = 0; i < n; i++) perm[i] = i;
    queue<vector<int> > q;
    q.push(perm);
    to_sort[perm] = 0;
    while(!q.empty()){
        vector<int> here = q.front();
        q.pop();
        int cost = to_sort[here];
        for(int i = 0; i< n; i++){
            for(int j = i + 2; j <= n; j++){
                reverse(here.begin() + i, here.begin() + j);
                if(to_sort.count(here) == 0){
                    to_sort[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
}

int solve(const vector<int>& perm){
    int n = perm.size();
    vector<int> fixed(n);
    for(int i = 0; i < n; i++){
        int smaller = 0;
        for(int j = 0; j < n; j++){
            if(perm[j] < perm[i])
                smaller++;
        }
        fixed[i] = smaller;
    }
    return to_sort[fixed];
}


int main(){
    freopen("SORTING_GAME.txt", "r", stdin);
    int TC, val;
    scanf("%d", &TC);
    for(int tc = 0; tc < TC; tc++){
        scanf("%d", &N);
        vector<int> vec(N);
        for(int j = 0; j < N; ++j){
            scanf("%d", &val);
            vec[j] = val;
        }
        precalc(N);
        printf("%d\n", solve(vec));
    }
}
