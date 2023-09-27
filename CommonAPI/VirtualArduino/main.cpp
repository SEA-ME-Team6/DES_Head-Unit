#include "CanSender.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    CanSender sender("can0");
    float data = 0.0f;

    while (true) {
        sender.sendData(data);
        std::cout << "Sent data: " << data << std::endl;
        data += 1.0f;
        sleep(1); 
    }

    return 0;
}
