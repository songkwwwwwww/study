#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;


int tree[30][2];

void postorder(int node)
{
	printf("%c", node + 'A' -1);
	if(tree[node][0] != 0)
		postorder(tree[node][0]);
	if(tree[node][1] != 0)
		postorder(tree[node][1]);

}

void preorder(int node)
{
	if(tree[node][0] != 0)
		preorder(tree[node][0]);
	if(tree[node][1] != 0)
		preorder(tree[node][1]);
	printf("%c", node + 'A' -1);
}
void inorder(int node)
{
	if(tree[node][0] != 0)
		inorder(tree[node][0]);
	printf("%c", node + 'A' -1);
	if(tree[node][1] != 0)
		inorder(tree[node][1]);

}


int main(){
    freopen("1991.txt", "r", stdin);
    int N; // 1 <= N <= 26;
    scanf("%d", &N);
    char v, l, r;
	for(int i = 0; i < N; i++)
	{
        cin >> v >> l >> r;
        if(l != '.')
			tree[v - 'A' + 1][0] = l - 'A' + 1;
		if(r != '.')
			tree[v - 'A' + 1][1] = r - 'A' + 1;
	}
	postorder(1);
	printf("\n");
    inorder(1);
	printf("\n");
    preorder(1);
	printf("\n");
}