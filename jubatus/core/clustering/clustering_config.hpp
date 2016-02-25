// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2013 Preferred Networks and Nippon Telegraph and Telephone Corporation.
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

#ifndef JUBATUS_CORE_CLUSTERING_CLUSTERING_CONFIG_HPP_
#define JUBATUS_CORE_CLUSTERING_CLUSTERING_CONFIG_HPP_

#include <string>
#include <msgpack.hpp>
#include "jubatus/util/data/serialization.h"
#include "jubatus/util/text/json.h"

namespace jubatus {
namespace core {
namespace clustering {

struct clustering_config {
  clustering_config()
      : k(2),
        compressor_method("simple"),
        bucket_size(10000),
        bucket_length(2),
        bicriteria_base_size(10),
        compressed_bucket_size(200),
        forgetting_factor(2.0),
        forgetting_threshold(0.05),
        seed(0) {
  }

  int k;

  std::string compressor_method;

  int bucket_size;
  int bucket_length;
  int bicriteria_base_size;
  int compressed_bucket_size;
  double forgetting_factor;
  double forgetting_threshold;
  int64_t seed;

  MSGPACK_DEFINE(
      k,
      compressor_method,
      bucket_size,
      bucket_length,
      bicriteria_base_size,
      compressed_bucket_size,
      forgetting_factor,
      forgetting_threshold,
      seed);

  template<typename Ar>
  void serialize(Ar& ar) {
    ar & JUBA_MEMBER(k)
        & JUBA_MEMBER(compressor_method)
        & JUBA_MEMBER(bucket_size)
        & JUBA_MEMBER(bucket_length)
        & JUBA_MEMBER(bicriteria_base_size)
        & JUBA_MEMBER(compressed_bucket_size)
        & JUBA_MEMBER(forgetting_factor)
        & JUBA_MEMBER(forgetting_threshold)
        & JUBA_MEMBER(seed);
  }
};

}  // namespace clustering
}  // namespace core
}  // namespace jubatus

#endif  // JUBATUS_CORE_CLUSTERING_CLUSTERING_CONFIG_HPP_
