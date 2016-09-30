/* Hernan Palombo */
/* set_difference example */

#include <iostream>     // std::cout
#include <algorithm>    // std::set_difference, std::sort
#include <vector>       // std::vector

using namespace std;

vector<int> u(vector<int>A,vector<int>B)
{ 
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  int size;
  if (A.size() > B.size()) size = A.size();
  else size = B.size();
  vector<int> C(size*2);

  vector<int>::iterator it= set_union(A.begin(),A.end(),B.begin(),B.end(),C.begin());
  C.resize(it-C.begin());
  return C;
}

vector<int> i(vector<int>A,vector<int>B)
{ 
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  int size;
  if (A.size() > B.size()) size = A.size();
  else size = B.size();
  vector<int> C(size);

  vector<int>::iterator it= set_intersection(A.begin(),A.end(),B.begin(),B.end(),C.begin());
  C.resize(it-C.begin());
  return C;
}

int main () {
  // read input directly into vector 
  /*
  */

  // or use array and then convert into vector
  int a[] = {5,10,15,20,25};
  int b[] = {50,40,30,20,10};
  int c[] = {5,15};
  vector<int> A(a,a + sizeof a / sizeof a[0]);
  vector<int> B(b,b + sizeof b / sizeof b[0]);
  vector<int> C(c,c + sizeof c / sizeof c[0]);
  vector<int>::iterator it;

  vector<int> v = u(A,B);
  for (it=v.begin(); it!=v.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  v = i(v,C);
  for (it=v.begin(); it!=v.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  v = u(v,B);
  for (it=v.begin(); it!=v.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}

