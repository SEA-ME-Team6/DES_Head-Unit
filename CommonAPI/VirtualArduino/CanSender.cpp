#include "CanSender.hpp"
#include <iostream>

CanSender::CanSender(const char* interface_name) {
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Error while opening socket");
        exit(-1);
    }

    strcpy(ifr.ifr_name, interface_name);
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family  = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error in socket bind");
        exit(-2);
    }
}

CanSender::~CanSender() {
    close(s);
}

void CanSender::sendData(float data) {
    frame.can_id = 0x123; 
    frame.can_dlc = sizeof(float);
    memcpy(frame.data, &data, sizeof(float));

    if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        perror("Error writing to CAN socket");
    }
}
