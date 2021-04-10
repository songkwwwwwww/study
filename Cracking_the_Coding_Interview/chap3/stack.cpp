#include <cstdio>
#include <iostream>
#include <cassert>

#include <vector>

template <typename T>
class my_stack {
public:
    T pop() {
	if (stack.empty())
	    return 0;

	T ret = peek();
	stack.pop_back();
	return ret;
    }

    void push(T item) {
	stack.push_back(item);
    }

    T peek() {
	return stack[stack.size() - 1];
    }

    bool is_empty() {
	return stack.empty();
    }
private:
    std::vector<T> stack;
};


int main() {
    my_stack<int> stack;

    int iter = 10;

    for (int i = 0; i < iter; i++) {
	stack.push(i);
	//printf("stack.peek() == %d, i = %d\n", stack.peek(), i);
	assert(stack.peek() == i);
    }
    
    for (int i = 0; i < iter; i++) {
	stack.pop();
    }
    assert(stack.is_empty() == true);
}
