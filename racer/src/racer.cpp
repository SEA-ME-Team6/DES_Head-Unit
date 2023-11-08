#include "racer.h"
#include <iostream>

Racer::Racer() {
    /*
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
    */
}

Racer::~Racer() {
    /*
    std::cout << "piracer remove start" << std::endl;
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    std::cout << "piracer remove finish" << std::endl;
    Py_FinalizeEx();
    */
}


void Racer::setGear(uint8_t gear){
    gearStatus = gear;
    std::cout << "Head unit set gear to " << gearStatus << std::endl;
}

void Racer::set_steering_percent(float steering) {
    if (gearStatus == 2 && gearStatus == 3) {
        //PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", steering);
        std::cout << "set steering" << steering << std::endl;
    }
}

void Racer::set_throttle_percent(float throttle) {
    if (gearStatus == 1 && gearStatus == 3) {
        //PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", throttle);
        std::cout << "set throttle" << throttle << std::endl;
    }
}

uint32_t Racer::getBatttery() {
    /*
    pVoltage = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    voltage = PyFloat_AsDouble(pVoltage);
    batteryStatus = (uint32_t)((voltage/3-3.1)*100/1.1);
    return batteryStatus;
    */
}

uint8_t Racer::getGear() const{
    return gearStatus;
}
