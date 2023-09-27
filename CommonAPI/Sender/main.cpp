#include "Sender.hpp"
#include <iostream>

int main() {
    CanReceive receiver("can0");

    while (true) {
        float rpm, speed;
        if (receiver.getData(rpm, speed)) {
            std::cout << "RPM: " << rpm << ", Speed: " << speed << std::endl;
        } else {
            std::cout << "Error receiving data." << std::endl;
        }

        usleep(200000); // Sleep for 200 milliseconds
    }

    return 0;
}
