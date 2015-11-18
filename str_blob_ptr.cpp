#include "str_blob_ptr.h"

using namespace std;

shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const
{
  auto ret = wptr.lock();
  if (!ret) throw runtime_error("unbound StrBlobPtr");
  if (i >= ret->size()) throw out_of_range(msg);
  return ret;
}

string&
StrBlobPtr::deref() const
{
  auto p = check(curr, "derefence past end");
  return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}