// This file is auto-generated from classifier.idl(0.4.5-350-g9c67807) with jenerator version 0.4.5-375-g07d06b7/develop
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>
#include "jubatus/util/lang/shared_ptr.h"

#include "../../server/framework.hpp"
#include "classifier_serv.hpp"

namespace jubatus {
namespace server {

class classifier_impl : public jubatus::server::common::mprpc::rpc_server {
 public:
  explicit classifier_impl(const jubatus::server::framework::server_argv& a):
    rpc_server(a.timeout),
    p_(new jubatus::server::framework::server_helper<classifier_serv>(a,
        false)) {

    rpc_server::add<int32_t(std::string, std::vector<labeled_datum>)>("train",
        jubatus::util::lang::bind(&classifier_impl::train, this, jubatus::util::lang::_2));
    rpc_server::add<std::vector<std::vector<estimate_result> >(std::string,
        std::vector<jubatus::core::fv_converter::datum>)>("classify",
        jubatus::util::lang::bind(&classifier_impl::classify, this, jubatus::util::lang::_2));
    rpc_server::add<bool(std::string)>("clear", jubatus::util::lang::bind(
        &classifier_impl::clear, this));

    rpc_server::add<std::string(std::string)>("get_config", jubatus::util::lang::bind(
        &classifier_impl::get_config, this));
    rpc_server::add<bool(std::string, std::string)>("save", jubatus::util::lang::bind(
        &classifier_impl::save, this, jubatus::util::lang::_2));
    rpc_server::add<bool(std::string, std::string)>("load", jubatus::util::lang::bind(
        &classifier_impl::load, this, jubatus::util::lang::_2));
    rpc_server::add<std::map<std::string, std::map<std::string, std::string> >(
        std::string)>("get_status", jubatus::util::lang::bind(
        &classifier_impl::get_status, this));
  }

  int32_t train(const std::vector<labeled_datum>& data) {
    JWLOCK_(p_);
    return get_p()->train(data);
  }

  std::vector<std::vector<estimate_result> > classify(
      const std::vector<jubatus::core::fv_converter::datum>& data) {
    JRLOCK_(p_);
    return get_p()->classify(data);
  }

  bool clear() {
    JWLOCK_(p_);
    return get_p()->clear();
  }

  std::string get_config() {
    JRLOCK_(p_);
    return get_p()->get_config();
  }

  bool save(const std::string& id) {
    JWLOCK_(p_);
    return get_p()->save(id);
  }

  bool load(const std::string& id) {
    JWLOCK_(p_);
    return get_p()->load(id);
  }

  std::map<std::string, std::map<std::string, std::string> > get_status() {
    JRLOCK_(p_);
    return p_->get_status();
  }

  int run() { return p_->start(*this); }
  jubatus::util::lang::shared_ptr<classifier_serv> get_p() { return p_->server(); }

 private:
  jubatus::util::lang::shared_ptr<jubatus::server::framework::server_helper<classifier_serv> > p_;
};

}  // namespace server
}  // namespace jubatus

int main(int argc, char* argv[]) {
  return
    jubatus::server::framework::run_server<jubatus::server::classifier_impl>
      (argc, argv, "classifier");
}
