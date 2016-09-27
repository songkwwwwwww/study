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
//#include <unordered_map> // c++11

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

typedef pair<int, int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력
Standard input consists of several lines, each containing a pair of integers separated by one or more space characters, specifying the weight and storage ability of a doll. The weight of the doll is in grams. The storage ability, also in grams, is the doll's overall storage capacity, including its own weight. That is, a doll weighing 400g with a strength of 900g could carry 500g of dolls inside it. There are at most 6000 dolls. The maximum weight of any doll is 100000g and the maximum storage capacity is 20000000g.

출력
Your output is a single integer indicating the maximum number of dolls that can be nested without exceeding the storage ability of any one.
*/


const int MAX_N = 6000;
const int MAX_W = 100000;
const int MAX_C = 20000000;
int N;
//int d[MAX_N][MAX_W];

struct doll{
    int weight;
    int storage;
};

bool cmp(doll a, doll b){
    if(a.weight >= b.weight){
        if(a.storage >= b.storage)
            return true;
        else //a.storage < b.storage
            return false;
    }
    else{ // a.weigth < b.weight
        return false;
    }
}
doll dolls[MAX_N];

int main(){
    freopen("10462.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int weight, storage;
    while(scanf("%d %d", &weight, &storage) == 2){
        dolls[N].weight = weight;
        dolls[N].storage = storage;
        N++;
    }
    sort(dolls, dolls + N, cmp);
    for(int i = 0; i < N; i++)
        printf("%d %d\n", dolls[i].weight, dolls[i].storage);
    printf("hello\n");
}