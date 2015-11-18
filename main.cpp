#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "str_blob.h"

using namespace::std;

int main() {
  StrBlob blob;

//  blob.front();
//  blob.back();
//  blob.pop_back();

  blob.push_back("a");
  string a = blob.front();
  string b = blob.back();
  cout << a;
  cout << b;
  cout << endl;

  unique_ptr<string> str(new string("ooxx"));
  unique_ptr<string> ss;
  ss.reset(str.release());

  auto p = make_shared<int>(42);
  weak_ptr<int> wp(p);

  if (auto np = wp.lock()) {
    cout << *np << endl;
  }

}
