/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_RPM_Status_STUB_DEFAULT_HPP_
#define V1_COMMONAPI_RPM_Status_STUB_DEFAULT_HPP_


#include <CommonAPI/Export.hpp>

#include <v1/commonapi/RPMStatusStub.hpp>
#include <cassert>
#include <sstream>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v1 {
namespace commonapi {

/**
 * Provides a default implementation for RPMStatusStubRemoteEvent and
 * RPMStatusStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 *
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class COMMONAPI_EXPORT_CLASS_EXPLICIT RPMStatusStubDefault
    : public virtual RPMStatusStub {
public:
    COMMONAPI_EXPORT RPMStatusStubDefault()
        : remoteEventHandler_(this),
          interfaceVersion_(RPMStatus::getInterfaceVersion()) {
    }

    COMMONAPI_EXPORT const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return interfaceVersion_;
    }

    COMMONAPI_EXPORT RPMStatusStubRemoteEvent* initStubAdapter(const std::shared_ptr< RPMStatusStubAdapter> &_adapter) {
        CommonAPI::Stub<RPMStatusStubAdapter, RPMStatusStubRemoteEvent>::stubAdapter_ = _adapter;
        return &remoteEventHandler_;
    }

    COMMONAPI_EXPORT virtual const float &getRpmAttribute() {
        return rpmAttributeValue_;
    }
    COMMONAPI_EXPORT virtual const float &getRpmAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return getRpmAttribute();
    }
    COMMONAPI_EXPORT virtual void setRpmAttribute(float _value) {
        const bool valueChanged = trySetRpmAttribute(std::move(_value));
        if (valueChanged) {
            fireRpmAttributeChanged(rpmAttributeValue_);
        }
    }
    COMMONAPI_EXPORT virtual void setRpmAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, float _value) {
        (void)_client;
        setRpmAttribute(_value);
    }


protected:
    COMMONAPI_EXPORT virtual bool trySetRpmAttribute(float _value) {
        if (!validateRpmAttributeRequestedValue(_value))
            return false;

        bool valueChanged;
        std::shared_ptr<RPMStatusStubAdapter> stubAdapter = CommonAPI::Stub<RPMStatusStubAdapter, RPMStatusStubRemoteEvent>::stubAdapter_.lock();
        if(stubAdapter) {
            stubAdapter->lockRpmAttribute(true);
            valueChanged = (rpmAttributeValue_ != _value);
            rpmAttributeValue_ = std::move(_value);
            stubAdapter->lockRpmAttribute(false);
        } else {
            valueChanged = (rpmAttributeValue_ != _value);
            rpmAttributeValue_ = std::move(_value);
        }

       return valueChanged;
    }
    COMMONAPI_EXPORT virtual bool validateRpmAttributeRequestedValue(const float &_value) {
        (void)_value;
        return true;
    }
    COMMONAPI_EXPORT virtual void onRemoteRpmAttributeChanged() {
        // No operation in default
    }
    class COMMONAPI_EXPORT_CLASS_EXPLICIT RemoteEventHandler: public virtual RPMStatusStubRemoteEvent {
    public:
        COMMONAPI_EXPORT RemoteEventHandler(RPMStatusStubDefault *_defaultStub)
            : 
              defaultStub_(_defaultStub) {
        }

        COMMONAPI_EXPORT virtual void onRemoteRpmAttributeChanged() {
            assert(defaultStub_ !=NULL);
            defaultStub_->onRemoteRpmAttributeChanged();
        }

        COMMONAPI_EXPORT virtual bool onRemoteSetRpmAttribute(float _value) {
            assert(defaultStub_ !=NULL);
            return defaultStub_->trySetRpmAttribute(std::move(_value));
        }

        COMMONAPI_EXPORT virtual bool onRemoteSetRpmAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, float _value) {
            (void)_client;
            return onRemoteSetRpmAttribute(_value);
        }

    private:
        RPMStatusStubDefault *defaultStub_;
    };
protected:
    RPMStatusStubDefault::RemoteEventHandler remoteEventHandler_;

private:

    float rpmAttributeValue_ {};

    CommonAPI::Version interfaceVersion_;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_RPM_Status_STUB_DEFAULT
