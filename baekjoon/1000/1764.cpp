#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
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

string no_here[500000];
string both[500000];
int n_both;

string s; char t[22];

int main(){
    freopen("1764.txt", "r", stdin);
    
    int N, M; // 1 <= N, M <= 50,0000 
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%s", t);
        no_here[i] = t;
        //cin >> no_here[i];
    }
    sort(no_here, no_here + N);

    for(int i = 0; i < M; i++){
        scanf("%s", t);
        s = t;
        //cin >> s;
        if(binary_search(no_here, no_here + N, s)) both[n_both++] = s;
    }
    sort(both, both + n_both);
    printf("%d\n", n_both);
    //cout << n_both << endl;
    for(int i = 0; i < n_both; i++) puts(both[i].c_str()); 
        //cout << both[i] << endl;
}


/*

int main(){
    freopen("1764.txt", "r", stdin);
    
    int N, M; // 1 <= N, M <= 50,0000 
    scanf("%d %d", &N, &M);
    set<string> s;
    vector<string> v;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        s.insert(str);
    }
    for(int i = 0; i < M; i++){
        string str;
        cin >> str;
        set<string>::iterator it;
        if((it = s.find(str)) != s.end()){
            v.push_back(*it);
            s.erase(it);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(vector<string>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << endl;
}
*/