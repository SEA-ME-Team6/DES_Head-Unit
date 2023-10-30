/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_Gear_Selection_STUB_HPP_
#define V1_COMMONAPI_Gear_Selection_STUB_HPP_

#include <functional>
#include <sstream>




#include <v1/commonapi/GearSelection.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif


#include <mutex>

#include <CommonAPI/Stub.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service GearSelection. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class GearSelectionStubAdapter
    : public virtual CommonAPI::StubAdapter,
      public virtual GearSelection {
 public:
    ///Notifies all remote listeners about a change of value of the attribute gear.
    virtual void fireGearAttributeChanged(const uint32_t &gear) = 0;


    virtual void deactivateManagedInstances() = 0;

    void lockGearAttribute(bool _lockAccess) {
        if (_lockAccess) {
            gearMutex_.lock();
        } else {
            gearMutex_.unlock();
        }
    }

protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
    std::recursive_mutex gearMutex_;

};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for GearSelection.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class GearSelectionStubRemoteEvent
{
public:
    virtual ~GearSelectionStubRemoteEvent() { }

    /// Verification callback for remote set requests on the attribute gear
    virtual bool onRemoteSetGearAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _value) = 0;
    /// Action callback for remote set requests on the attribute gear
    virtual void onRemoteGearAttributeChanged() = 0;
};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service GearSelection to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class GearSelectionStub
    : public virtual CommonAPI::Stub<GearSelectionStubAdapter, GearSelectionStubRemoteEvent>
{
public:

    virtual ~GearSelectionStub() {}
    void lockInterfaceVersionAttribute(bool _lockAccess) { static_cast<void>(_lockAccess); }
    bool hasElement(const uint32_t _id) const {
        return (_id < 1);
    }
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) = 0;

    /// Provides getter access to the attribute gear
    virtual const uint32_t &getGearAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireGearAttributeChanged(uint32_t _value) {
    auto stubAdapter = CommonAPI::Stub<GearSelectionStubAdapter, GearSelectionStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireGearAttributeChanged(_value);
    }
    void lockGearAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<GearSelectionStubAdapter, GearSelectionStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockGearAttribute(_lockAccess);
    }


    using CommonAPI::Stub<GearSelectionStubAdapter, GearSelectionStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<GearSelectionStubAdapter, GearSelectionStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<GearSelectionStubAdapter, GearSelectionStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef GearSelectionStubRemoteEvent RemoteEventType;
    typedef GearSelection StubInterface;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_Gear_Selection_STUB_HPP_
