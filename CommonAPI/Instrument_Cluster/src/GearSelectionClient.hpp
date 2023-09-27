#ifndef GEARSELECTIONCLIENT_HPP
#define GEARSELECTIONCLIENT_HPP

#include <memory>
#include <QObject>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearSelectionProxy.hpp>

using namespace v1::commonapi;

class GearSelectionClient : public QObject {
    Q_OBJECT
    //Q_PROPERTY(int gear READ getGear NOTIFY gearChanged)
public:
    GearSelectionClient();
    void run();

private:

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearSelectionProxy<>> myProxy_;

};

#endif // GEARSELECTIONCLIENT_HPP_





