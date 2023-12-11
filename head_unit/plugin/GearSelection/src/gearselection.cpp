#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "gearselection.h"

using namespace v1::commonapi;

GearSelection::GearSelection() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";

    //gear client
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "client-gear";
    gearProxy = runtime->buildProxy<GearStatusProxy>(domain, gear_instance, gear_connection);
    std::cout << "Waiting for GearSelection service to become available." << std::endl;

    // If HU start, Gear value have to set racer gear value
    // So When HU request value of 7 to racer, racer response saving gear info
    CommonAPI::CallStatus callStatus;
    uint8_t returnedGear;
    gearProxy->gearselection(7, callStatus, returnedGear);
    emit gearChanged();

    //rpm client
    std::string rpm_instance = "RPMStatus";
    std::string rpm_connection = "client-rpm";
    rpmProxy = runtime->buildProxy<RPMStatusProxy>(domain, rpm_instance, rpm_connection);
    std::cout << "Waiting for Speed service to become available." << std::endl;
    rpmProxy->getRpmAttribute().getChangedEvent().subscribe(
        [&](const float& rpm_){
            rpm_check = rpm_;
        }
    );
}

void GearSelection::changegear(quint8 gearselect){
    CommonAPI::CallStatus callStatus;
    uint8_t returnedGear;

    if(rpm_check < 5) {
        gearProxy->gearselection(gearselect, callStatus, returnedGear);
        if (callStatus == CommonAPI::CallStatus::SUCCESS) {
            std::cout << "Gear set successfully. Returned gear: " << (int)returnedGear <<std::endl;
            gear = returnedGear;
            emit gearChanged();
        } else {
            std::cout << "Failed to set gear." << std::endl;
        }
    }
}

uint8_t GearSelection::getGear() const {
    std::cout << "HU return Gear: " << gear << std::endl;
    return gear;
}