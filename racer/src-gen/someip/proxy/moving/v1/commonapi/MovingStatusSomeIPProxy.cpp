/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/MovingStatusSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createMovingStatusSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< MovingStatusSomeIPProxy>(_address, _connection);
}

void initializeMovingStatusSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.MovingStatus:v1_0:MovingStatus",
        0x1238, 0x567d, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.MovingStatus:v1_0",
        &createMovingStatusSomeIPProxy);
}

INITIALIZER(registerMovingStatusSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeMovingStatusSomeIPProxy);
}

MovingStatusSomeIPProxy::MovingStatusSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          steering_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x80f6), CommonAPI::SomeIP::event_id_t(0x80ec), CommonAPI::SomeIP::method_id_t(0xbbc), false, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE, false, CommonAPI::SomeIP::method_id_t(0xbbd), false, static_cast< CommonAPI::EmptyDeployment* >(nullptr)),
          throttle_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x8100), CommonAPI::SomeIP::event_id_t(0x80f6), CommonAPI::SomeIP::method_id_t(0xbc6), false, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE, false, CommonAPI::SomeIP::method_id_t(0xbc7), false, static_cast< CommonAPI::EmptyDeployment* >(nullptr))
{
}

MovingStatusSomeIPProxy::~MovingStatusSomeIPProxy() {
    completed_.set_value();
}

MovingStatusSomeIPProxy::SteeringAttribute& MovingStatusSomeIPProxy::getSteeringAttribute() {
    return steering_;
}
MovingStatusSomeIPProxy::ThrottleAttribute& MovingStatusSomeIPProxy::getThrottleAttribute() {
    return throttle_;
}


void MovingStatusSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> MovingStatusSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace commonapi
} // namespace v1