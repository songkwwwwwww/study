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
#include <unordered_map>

#include <utility> // std::pair

#include <functional> // greater, less
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int INF = 987654321;
const int MAX_V = 20000;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int MAX_F = 100000;

int F;
int p[200001];
int counter[200001];

int find(int n){
	if(p[n] == n) return n;
	else return p[n] = find(p[n]);
}


int merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return counter[a]; 
	p[b] = a;
    counter[a] += counter[b];
    counter[b] = 1;
    return counter[a];    
}

int main(){
    freopen("4195.txt", "r", stdin);
    int TC; 
    scanf("%d", &TC);
    
    while(TC--){
        unordered_map<string, int> m;
        scanf("%d", &F);
        for(int i = 1; i <= 2 * F; i++){
            p[i] = i;
            counter[i] = 1;
        }
        char cstr1[21], cstr2[21];
        int num = 1;
        for(int i = 0; i < F; i++){
            int s1_num, s2_num;
    
            scanf("%s %s", cstr1, cstr2);
            string str1(cstr1), str2(cstr2);

            if(m.count(str1) == 0) m[str1] = num++;
            s1_num = m[str1];

            if(m.count(str2) == 0) m[str2] = num++;
            s2_num = m[str2];

            printf("%d\n", merge(s1_num, s2_num));
        }
    }
}