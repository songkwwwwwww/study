/*
Given a text txt[0..n-1] and a pattern pat[0..m-1],
write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

http://www.geeksforgeeks.org/searching-for-patterns-set-1-naive-pattern-searching/
*/


#include <iostream>
#include <string>
#include <vector>


/*

	@param	txt	the text
	@param	pat	the pattern

	@return	vector of index
	
	
	if N = length of text, M =  length of pattern
	theh, time complexity    :    O( N * M)
*/
std::vector<int> naive_search(const std::string& txt, const std::string& pat){
	std::vector<int> result;
	int P = pat.size();	// length of pat

	for(int begin = 0; begin < txt.size() - P; begin++){
		int j;
		for(j = 0; j < P; j++){
			if(txt[begin + j] != pat[j]) break;
		}
		if(j == P) result.push_back(begin);
	}
	return result;
}


int main(){
	std::string txt("AABAACAADAABAAABAA");
	std::string pat("AABA");

	std::vector<int> v = naive_search(txt, pat);
	for(int i = 0; i < v.size(); i++){
		std::cout << "Pattern found at index " << v[i] << std::endl;
	}

	return 0;
}
