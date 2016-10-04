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
int main(){
    freopen("1158.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> survivors; survivors.reserve(N);
    for(int i = 1; i <= N; i++) survivors.push_back(i); 
 
    int pos = 0, remainder = N;
    printf("<");
    while(remainder){
        pos = (pos + M - 1) % remainder; 
        if(!(remainder - 1)){
            printf("%d>\n", survivors[pos]);
            break;
        }
        printf("%d, ", survivors[pos]);
        survivors.erase(survivors.begin() + pos);
        remainder--;
    }
}


/*
int main(){
    freopen("1158.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);

    list<int> survivors;
    for(int i = 1; i <= N; i++) survivors.push_back(i); 
 
    list<int>::iterator kill = survivors.begin();

    for(int i = 0; i < M - 1; i++){
        kill++;
        if(kill == survivors.end()) kill = survivors.begin();
    }

    vector<int> order; order.reserve(N);

    while(N > 0){
        order.push_back(*kill);
        kill = survivors.erase(kill);
        if(kill == survivors.end()) kill = survivors.begin();
        N--;
        for(int i = 0; i < M - 1; i++){
            kill++;
            if(kill == survivors.end()) kill = survivors.begin();
        }
    }
    printf("<");
    for(int i = 0; i < order.size() - 1; i++)
        printf("%d, ", order[i]);
    printf("%d>\n", order[order.size() - 1]);
}

*/