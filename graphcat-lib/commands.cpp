#include "commands.hpp"

#ifdef _WIN32
#pragma once
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

Message CommandCreator::ping_pong() {
    Message c;
    c.body["command"] = "example.ping_pong";
    c.body["answer"] = json{};
    json args;
    args["ping"] = 0xdeadbeef;
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.data_rate = 0xde;
    c.header.packetsize = htonl(buf.size());
    return c;
}
