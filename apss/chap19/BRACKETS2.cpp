#include <iostream>		//
#include <cstdio>		
#include <stack>		// std::stack
#include <string>
/*
	@input
3
()()
({[}])
({}[(){}])

	@output
YES
NO
YES

*/

/*
	둥근 괄호는 (로 열고, )로 닫습니다.
	중괄호는 {로 열고, }로 닫습니다.
	대괄호는 [로 열고, ]로 닫습니다.

	모든 괄호는 해당하는 짝이 있어야 합니다. 이때 (는 )와, {는 }와, [는 ]와 짝을 이뤄야만 합니다.
	모든 괄호 쌍은 먼저 열린 뒤 닫힙니다.
	한 괄호 쌍이 다른 괄호 쌍과 서로 '교차해' 있으면 안됩니다. 이 정의에 의하면 [(])는 짝이 맞지 않는 경우입니다.
*/

bool wellMatched(const std::string& formula){
	//여는 괄호 문자들과 닫는 괄호 문자들
	const std::string opening("({["), closing(")}]");
	std::stack<char> openStack;

	for(int i = 0; i < formula.size(); i++){
		// 여는 괄호인지 닫는 괄호인지 확인한다
		if(opening.find(formula[i]) != -1)
			openStack.push(formula[i]);
		else{
			if(openStack.empty()) return false;
			if(opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			openStack.pop();
		}
	}
	return openStack.empty();
}


int main(){
	int TC;		// test case TC (1<= TC <= 100)
	std::string str;
	str.reserve(10000);

	if(freopen("BRACKETS2.txt", "r", stdin) == NULL)
		std::cout << "file open failed" << std::endl;
	
	std::cin >> TC;	
	for(int i = 0; i < TC; i++){
		std::cin >> str;
		bool result = wellMatched(str);
		if(result) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;
	}
}
