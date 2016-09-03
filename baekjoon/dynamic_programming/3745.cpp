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

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*
입력
입력은 여러개의 테스트 케이스로 이루어져 있다. 
각 테스트 케이스의 
첫째 줄에는 주가를 관찰한 날의 수 N (N ≤ 100000)이 주어진다. 
둘째 줄에는 관찰한 주가가 첫 날부터 순서대로 주어진다. 
주가는 한 개 이상의 공백으로 구분되어 있다.

출력
각 테스트 케이스에 대해서 입력으로 주어진 주가의 가장 긴 오름세의 길이를 출력한다.
*/
int N;
int a[100001];
int d[100001];

int LIS(vector<int>& arr){
    vector<int> v(1, arr[0]);
    for(int i=1; i<arr.size(); ++i){
        if(v.back() < arr[i]){
            v.push_back(arr[i]);
        } else {
            *lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
        }
    }
    return v.size();
}

int main(){
    freopen("3745.txt", "r", stdin);
    int i, n;
    while(~scanf("%d", &n)){
        vector<int> a(n);
        for(i=0; i<n; ++i) scanf("%d", &a[i]);
        printf("%d\n", LIS(a));
    }
    return 0;
}