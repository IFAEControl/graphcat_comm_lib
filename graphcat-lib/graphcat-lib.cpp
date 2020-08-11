#include <iostream>

#include "graphcat-lib.hpp"
#include "commands.hpp"
#include "sockets.hpp"


void set_ip(const char* str) {
    set_dest_ip(str);
}

int gc_ping_pong() {
    CommandCreator c;
    auto cmd = c.ping_pong();
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    return 0;
}
