/*
https://en.wikipedia.org/wiki/Binary_tree

	#binary tree representation

	    S

	L       R


	S = root node
	L = left child node
	R = 

	preorder	: 	SLR
	inorder		:	LSR
	postorder	:	LRS
*/

#include <iostream>
#include <algorithm>	// std::find
#include <vector>	// std::vector
#include <cstdio>	// freopen()

/*
	JMB 689p
	code 21.4
*/

/*
	@param	v	tree vector
	@param	a	start index
	@param	b	end endex
	
	return vector in the range of a to b	//	[a, b)
*/
std::vector<int> slice(const std::vector<int>& v, int a, int b){
	return std::vector<int> (v.begin() + a, v.begin() + b);
}

/*
	@param	preoder	vector representation of preorder
	@param	inorder	vector representation of inorder
*/
void print_post_order(const std::vector<int>& preorder, const std::vector<int>& inorder){
	
	// the number of nodes
	const int N = preorder.size();

	// base condition
	if(preorder.empty())	return;

	// root node
	const int root = preorder[0];	

	// size of left trees
	const int L = std::find(inorder.begin(), inorder.end(), root) - inorder.begin();

	// size of right trees
	const int R = N - 1 - L;

	print_post_order(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	print_post_order(slice(preorder, L + 1, N), slice(inorder, L + 1, N));

	std::cout << root << ' ';
}




int main(){
	freopen("TRAVERSAL.txt", "r", stdin);

	int TC;

	std::cin >> TC;

	for(int i = 0; i < TC; i++){
		int size, n;
		std::cin >> size;
		std::vector<int> preorder;
		preorder.reserve(size);
		std::vector<int> inorder;
		inorder.reserve(size);

		for(int j = 0; j < size; j++){
			std::cin >> n;
			preorder.push_back(n);
		}
		for(int j = 0; j < size; j++){
			std::cin >> n;
			inorder.push_back(n);
		}
		print_post_order(preorder, inorder);
		std::cout << std::endl;
	}

}
