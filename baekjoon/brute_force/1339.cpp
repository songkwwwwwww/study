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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
첫째 줄에 수의 개수 N(<=10)이 주어진다.
둘째 줄부터 N개의 줄에 수가 한 줄에 하나씩 주어진다. 
수는 알파벳 대문자로만 이루어져있다. 
모든 수에 들어간 알파벳은 최대 10개이고, 수의 최대 길이는 8이다. 
서로 다른 문자는 서로 다른 수를 나타낸다.

출력
첫째 줄에 주어진 수의 합의 최대값을 출력한다.
*/
int N;
vector<string> v;

int val[10], cnt[8][10], result;
bool used[10];

int main(){
    freopen("1339.txt", "r", stdin);
    int n, m = 0;
	cin >> N;
	string S[10];
	for(int i=0; i<N; i++){
		cin >> S[i];
		if(S[i].size() < 8) S[i] = string(8 - S[i].size(), '0') + S[i];
	}
	sort(S, S+N);
    for(int i = 0; i < N; i++)
        cout << S[i] << endl;
    for(int i=0; i<8; i++){
		for(int j=N-1; j>=0; j--){
			if(S[j][i] >= 'A'){
				char c = S[j][i];
				for(int k=0; k<N; k++){
					for(int l=0; l<S[k].size(); l++){
						if(S[k][l] == c){
							cnt[8-S[k].size()+l][m]++;
							S[k][l] = '0'+m;
						}
					}
				}
				m++;
			}
		}
	}
    cout << "==========" << endl;
    for(int i = 0; i < N; i++)
        cout << S[i] << endl;
    
}