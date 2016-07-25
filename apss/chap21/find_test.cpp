// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

int main () {
  // using std::find with array and pointer:
  int myints[] = { 10, 20, 30, 40, 50 };
  std::vector<int> v(myints, myints + sizeof(myints)/sizeof(int));

  for(int i = 0; i < v.size(); i++)
	std::cout << v[i] << std::endl;

  //int * p;

  const int l = std::find(v.begin(), v.end(), 40) - v.begin();

// std::cout <<  find(v.begin(), v.end(), 40) << std::endl;

  std::cout << l << std::endl;
/*
  if (p != myints+4)
    std::cout << "Element found in myints: " << *p << '\n';
  else
    std::cout << "Element not found in myints\n";

  // using std::find with vector and iterator:
  std::vector<int> myvector (myints,myints+4);
  std::vector<int>::iterator it;

  it = find (myvector.begin(), myvector.end(), 30);
  if (it != myvector.end())
    std::cout << "Element found in myvector: " << *it << '\n';
  else
    std::cout << "Element not found in myvector\n";
*/
  return 0;
}
