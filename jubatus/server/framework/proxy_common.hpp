// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2011,2012 Preferred Infrastructure and Nippon Telegraph and Telephone Corporation.
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

#ifndef JUBATUS_SERVER_FRAMEWORK_PROXY_COMMON_HPP_
#define JUBATUS_SERVER_FRAMEWORK_PROXY_COMMON_HPP_

#include <string>
#include <utility>
#include <vector>

#include <glog/logging.h>
#include "jubatus/util/concurrent/lock.h"
#include "jubatus/util/concurrent/rwmutex.h"
#include "jubatus/util/lang/shared_ptr.h"
#include "jubatus/util/math/random.h"

#include "jubatus/core/common/exception.hpp"
#include "server_util.hpp"
#include "../common/lock_service.hpp"
#include "../common/cht.hpp"

namespace jubatus {
namespace server {
namespace framework {

class no_worker : public jubatus::core::common::exception::runtime_error {
 public:
  explicit no_worker(const std::string& name)
      : runtime_error("no server found: " + name) {
  }
};

class proxy_common {
 public:
  explicit proxy_common(const proxy_argv& a);
  virtual ~proxy_common();

 protected:
  void get_members_(
      const std::string& name,
      std::vector<std::pair<std::string, int> >& ret);

  void get_members_from_cht_(
      const std::string& name,
      const std::string& id,
      std::vector<std::pair<std::string, int> >& ret,
      size_t n);

  proxy_argv a_;
  jubatus::util::math::random::mtrand rng_;
  jubatus::util::concurrent::mutex mutex_;
  jubatus::util::lang::shared_ptr<common::lock_service> zk_;
};

}  // namespace framework
}  // namespace server
}  // namespace jubatus

#endif  // JUBATUS_SERVER_FRAMEWORK_PROXY_COMMON_HPP_
