#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> // max, min, sort, swap
#include <cmath> // abs

using namespace std;
typedef long long ll;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main(){
    freopen("6603.txt", "r", stdin);
    
    // 6 < k < 13, k는 주어지는 집합의 원소 개수
    // 이 집합에서 6개를 선택해야 한다.
    int k;
    while(true){
        scanf("%d", &k);
        if(k == 0) return 0;

        vector<int> a(k);
        // 집합 S는 오름차순으로 주어진다.
        for(int i = 0; i < k; i++) scanf("%d", &a[i]);

        // 해당 집합의 원소가 사용되는지 아닌지를 0, 1로 구분한다.
        // 각 집합에서 6개의 원소를 뽑기 때문에 1은 총 6개.
        vector<int> flag_array;
        flag_array.reserve(k);
        for(int i = 0; i < k - 6; i++) flag_array.push_back(0);
        for(int i = 0; i < 6; i++) flag_array.push_back(1);
        
        vector< vector<int> > storage; 

        do{
            vector<int> temp;
            temp.reserve(6);

            for(int i = 0; i < k; i++){
                if(flag_array[i] == 1)
                    temp.push_back(a[i]);    
            }
            storage.push_back( temp );
        }while(next_permutation(flag_array.begin(), flag_array.end()));
   
        sort(storage.begin(), storage.end());
        for(int i = 0; i < storage.size(); i++){
            vector<int>& v = storage[i];
            for(int i = 0; i < v.size(); i++) 
                printf("%d ", v[i]);
            printf("\n");
        }
        printf("\n");
    }
}