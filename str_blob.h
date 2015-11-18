#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

class StrBlobPtr;

class StrBlob {

friend class StrBlobPtr;

public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return data->size(); }
  bool empty() { return data->empty(); }
  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back();
  std::string& front() const;
  std::string& back() const;

private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;

//  StrBlobPtr begin() { return StrBlobPtr(*this); };
//  StrBlobPtr end() { auto ret = StrBlobPtr(*this, data->size()); return ret; }
};

class StrBlobPtr {
public:
  StrBlobPtr(): curr(0) {}
  StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
  std::string& deref() const;
  StrBlobPtr& incr();
private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};
