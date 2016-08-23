#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point {
    int x, y;
    Point() {
    }
    Point(int x, int y) : x(x), y(y) {
    }
    bool operator < (const Point &v) const {
        if (x == v.x) {
            return y < v.y;
        } else {
            return x < v.x;
        }
    }
};


int N; // 2 <= N <= 10,0000

vector< pair<int, int> > v;

int solve(){

}

int main(){
    freopen("2261.txt", "r", stdin);
    scanf("%d", &N);
    v.reserve(N);
    int a, b;
    for(int i = 0; i < N; i++){
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }


/*
    printf("test output\n");
    for(int i = 0; i < v.size(); i++)
        printf("%d %d\n", v[i].first, v[i].second);
  */  
        
}