/*
	KMP algorithm
*/

#include <iostream>
#include <vector>
#include <string>
/*
	JMB p652
	code 20.4
*/
/*
	#partial match table

	@param	p	the text to be analyzed
	@return table

	if N = length of p, then time complexity : O(N)
*/
std::vector<int> get_partial_match(const std::string& p){
	int m = p.size();
	std::vector<int> pi(m, 0);	// table to be filled

	int begin = 1, matched = 0;

	while(begin + matched < m){
		if(p[begin + matched] == p[matched]){
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else{
			if(matched == 0) ++begin;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}		
	}
	return pi;
}

/*
	JMB p649
	code 20.2
*/
/*
	#kmp_search

	@param	S	the text to be searched
	@param	W	the word sought
	@return the vector of starting index

	if N = length of S, then time complexity : O(N)
*/
std::vector<int> kmp_search(const std::string& S, const std::string& W){
	int s = S.size(), w = W.size();
	std::vector<int> result;

	std::vector<int> pi = get_partial_match(W);

	// begon = matched = 0
	int begin = 0, matched = 0;
	while(begin <= s - w){
		if(matched < w && S[begin + matched] == W[matched]){
			++matched;
			if(matched == w) result.push_back(begin);
		}
		else{
			if(matched == 0)
				++begin;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}			
		}
	}
	return result;
}


std::vector<int> kmp_search2(const std::string& S, const std::string& W){
	int n = S.size(), m = W.size();
	std::vector<int> ret;
	std::vector<int> pi = get_partial_match(W);
	int matched = 0;
	for(int i = 0; i < n; i++){
		while(matched > 0 && S[i] != W[matched])
			matched = pi[matched - 1];
		if(S[i] == W[matched]){
			++matched;
			if(matched == m){
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main(){
	std::string txt("AABAACAADAABAAABAA");
	std::string pat("AABA");

	std::vector<int> v = kmp_search2(txt, pat);
	for(int i = 0; i < v.size(); i++){
		std::cout << "Pattern found at index " << v[i] << std::endl;
	}

	return 0;
}
