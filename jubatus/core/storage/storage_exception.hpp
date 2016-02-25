// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2012,2013 Preferred Networks and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef JUBATUS_CORE_STORAGE_STORAGE_EXCEPTION_HPP_
#define JUBATUS_CORE_STORAGE_STORAGE_EXCEPTION_HPP_

#include <string>
#include "../common/exception.hpp"

namespace jubatus {
namespace core {
namespace storage {

class storage_exception
  : public common::exception::jubaexception<storage_exception> {
 public:
  explicit storage_exception(const std::string &msg): msg(msg) {}
  ~storage_exception() throw() {}
  const char *what() const throw() { return msg.c_str(); }

 private:
  std::string msg;
};

class length_unmatch_exception : public storage_exception {
 public:
  explicit length_unmatch_exception(const std::string &msg)
    : storage_exception(msg) {}
};
class type_unmatch_exception : public storage_exception {
 public:
  explicit type_unmatch_exception(const std::string &msg)
    : storage_exception(msg) {}
};
class argument_unmatch_exception : public storage_exception {
 public:
  explicit argument_unmatch_exception(const std::string &msg)
    : storage_exception(msg) {}
};
class array_range_exception : public storage_exception {
 public:
  explicit array_range_exception(const std::string &msg)
    : storage_exception(msg) {}
};

}  // namespace storage
}  // namespace core
}  // namespace jubatus

#endif  // JUBATUS_CORE_STORAGE_STORAGE_EXCEPTION_HPP_
