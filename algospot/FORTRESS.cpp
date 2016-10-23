
/*

	@input:
	TC		(1<= TC <=100)
	N		(1<= N <= 100)	// the number of city wall
	x_i y_i r_i	(0<= x_i, y_i <= 1000, 1<= r_i <= 1000, 0<= i < N)
			// the center of a circle : (x_i, y_i)
			// the radius of a circle : r_i



	@output:
	the longest length between two nodes

*/

#include <iostream>
#include <vector>
#include <cstdio>	// freopen()
#include <cmath>	// pow()
#include <algorithm>	// std::max()

// input data
int n, y[100], x[100], radius[100];

int sqr(int x){
	return x*x;
}

int sqrdist(int a, int b){
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

// does Circle a include Circle b
bool encloses(int a, int b){
	return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

bool isChild(int parent, int child){
	if(!encloses(parent, child)) return false;
	for(int i = 0; i < n; i++)
		if(i != parent && i != child && encloses(parent,i) && encloses(i, child)) return false;

	return true;
}

struct TreeNode{
	std::vector<TreeNode*> children;
};

int longest;

int height(TreeNode* root){
	std::vector<int> heights;
	for(int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));
	
	// base condition
	if(heights.empty()) return 0;
	
	sort(heights.begin(), heights.end());

	// if the number of children  >= 2, then compute the longest length
	if(heights.size() >= 2)
		longest = std::max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	
	return heights.back() + 1;
}

/*
	time complexity : O(n * lgn)
*/
int solve(TreeNode* root){
	longest = 0;
	int h = height(root);
	return std::max(longest, h);
}

TreeNode* getTree(int root){
	TreeNode* ret = new TreeNode();
	for(int ch = 0; ch < n; ch++){
		if(isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}
}

int main(){
	int TC;

	freopen("FORTRESS.txt", "r", stdin);

	std::cin >> TC;
	for(int i = 0; i < TC; i++){
		std::cin >> n;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < 3; k++){
				std::cin >> x[j] >> y[j] >> radius[j];
			}
		}
		TreeNode* t = getTree(0);
		int result = solve(t);
		std::cout << result << std::endl;
		//delete t;
	}
}
