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

int F;
int p[200000];

int Find(int a){
    if(p[a] < 0) return a;
    else p[a] = Find(p[a]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return ;
    if(p[a] < p[b]){
        p[a] += p[b];
        p[b] = a;
    }
    else{
        p[b] += p[a];
        p[a] = b;
    }
}



int main(){
    freopen("4195.txt", "r", stdin);
    int TC; 
    scanf("%d", &TC);
    unordered_map<string, int> m;
    
    while(TC--){
        memset(p, -1, sizeof(p));
        scanf("%d", &F);
        char cstr1[21], cstr2[21];
        int num = 0;
        for(int i = 0; i < F; i++){
            int s1_num, s2_num;
    
            scanf("%s %s", cstr1, cstr2);
            string str1(cstr1), str2(cstr2);
            if( m.count(str1) > 0){
                s1_num = m[str1];
            }
            else{
                m[str1] = num;
                s1_num = num;
                num++;
            }
            if( m.count(str2) > 0){
                s2_num = m[str2];
            }
            else{
                m[str2] = num;
                s2_num = num;
                num++;
            }
            //cout << "str1 :" << str1 << " ID : " << s1_num << endl;
            //cout << "str2 :" << str2 << " ID : " << s2_num << endl;
            Union(s1_num, s2_num);
            printf("%d\n", Find(s1_num));
        }
        for(int i = 0; i < num; i++)
            printf("%d ", p[i]);
        printf("\n");
            
        m.clear();
        cout << "finished" << endl;
    }
}

    
    /*
    string s("hello");
    
    m[s] = 1;
    for(auto iter : m){
        cout << "iter first : "<< iter.first << "\niter second : "
            << iter.second <<  endl;
    }

    m[s] = 2;
    for(auto iter : m){
        cout << "iter first : "<< iter.first << "\niter second : "
            << iter.second <<  endl;
    }
    */