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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MAX_N = 10;
int val[10], cnt[8][10], result;
bool used[10];

int main(){
    freopen("1339.txt", "r", stdin);
	int N, m = 0;
	cin >> N;
	string S[10];
	for(int i = 0; i < N; i++){
		cin >> S[i];
		if(S[i].size() < 8) S[i] = string(8-S[i].size(), '0') + S[i];
	}
	sort(S, S+N);
	for(int i = 0; i < N; i++){
		cout << S[i] << endl;
	}
	cout << "==========" << endl;
	for(int i = 0; i < 8; i++){
		for(int j = N -1; j >= 0; j--){
			if(S[j][i] >= 'A'){
				char c = S[j][i];
				for(int k = 0; k < N; k++){
					for(int l = 0; l < S[k].size(); l++){
						if(S[k][l] == c){
							cnt[8 - S[k].size() + l][m]++;
							S[k][l] = '0' + m;
						}
					}
				}
				m++;
			}
		}
	}
	for(int i = 0; i < N; i++){
		cout << S[i] << endl;
	}
}