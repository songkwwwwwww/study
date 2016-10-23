#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi

#include <cstdio>
#include <cstring>
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int MAX_N = 15;

int TC; // TC <= 50
int k; // 부분 문자열의 수  k ( 1 <= k <= 15)
// 각 문자열 조각의 길이는 1 <= len <= 20

string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N + 1][MAX_N + 1];

// O(k * 2^k) 개의 부분 문제에 대한 해답을 각각 O(k)개의 시간을 들여 계산하므로
// 총 시간 복잡도는 O(k^2 * 2^k)가 된다.
int restore(int last, int used){
    //base case
    if(used == (1 << k) - 1) return 0;

    //메모이제이션
    int& ret = cache[last][used];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = 0; next < k; next++){
        // 사용하지 않았다면 탐색
        if((used & (1 << next)) == 0){
            int cand = overlap[last][next] + restore(next, used | (1 << next));
            ret = max(ret, cand);
        }
    }
    return ret;
}



string reconstruct(int last, int used){
    // base case
    if(used == (1 << k) - 1) return "";
    // 다음에 올 문자열을 조각을 찾는다.
    for(int next = 0; next < k; next++){
        // next가 이미 사용되었다면 패스
        if(used & (1 << next)) continue;

        // next를 사용할 경우의 답이 최적해와 같다면 next를 사용한다.
        int cand = overlap[last][next] + restore(next, used | (1 << next));
        if(restore(last, used) == cand){
            return (word[next].substr(overlap[last][next]) +
                reconstruct(next, used | (1 << next)));
        }
    }
    // 위에서 끝나지 않으면 에러.
    return "error";
}

void initilize_overlap_array(){
    for(int i = 0; i < k; i++){
        overlap[k][i] = 0;
        overlap[i][k] = 0;
        
        for(int j = 0; j < k; j++){

            for(int len = min(word[i].size(), word[j].size()); len > 0 ; --len){
                if(word[i].substr(word[i].size() - len) ==
                    word[j].substr(0, len)){  
                    overlap[i][j] = len;
                    break;
                }

            }

        }

    }
}

// 주어진 문자열 조각들을 모두 부분 문자열로 포함하는 문자열 중 
// 가장 짧은 것을 계산하는 프로그램을 작성
int main(){
    freopen("RESTORE.txt", "r", stdin);
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d", &k);
        for(int i = 0; i < k; i++) cin >> word[i];
        // cache 초기화
        memset(cache, -1, sizeof(cache));
    	// 중복되는 문자열 조각 삭제
        while(true) {
    		bool removed = false;
    		for(int i = 0; i < k && !removed; i++)
    			for(int j = 0; j < k; j++)
    				if(i != j && word[i].find(word[j]) != -1) {
    					word[j] = word[k-1];
    					--k;
    					removed = true;
    				}

    		if(!removed) break;
    	}

        sort(word, word + k);
        initilize_overlap_array();
        //restore(k, 0);
    	cout << reconstruct(k, 0) << endl;
    }
}