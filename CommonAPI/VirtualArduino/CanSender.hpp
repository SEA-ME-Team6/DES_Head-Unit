#ifndef CAN_SENDER_HPP
#define CAN_SENDER_HPP

#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <cstring>
#include <unistd.h>

class CanSender {
private:
    int s;
    struct sockaddr_can addr;
    struct can_frame frame;
    struct ifreq ifr;

public:
    CanSender(const char* interface_name);
    ~CanSender();
    void sendData(float data);
};

#endif // CAN_SENDER_HPP
