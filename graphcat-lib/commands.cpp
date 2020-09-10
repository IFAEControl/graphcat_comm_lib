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
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::reset() {
    Message c;
    c.body["command"] = "gc.reset";
    c.body["answer"] = json{};
    json args{};
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::pixel_pulse_write() {
    Message c;
    c.body["command"] = "gc.pixel_pulse_write";
    c.body["answer"] = json{};
    json args{};
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::read_temperature() {
    Message c;
    c.body["command"] = "gc.read_temperature";
    c.body["answer"] = json{};
    json args{};
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::generate_pulse() {
    Message c;
    c.body["command"] = "gc.generate_pulse";
    c.body["answer"] = json{};
    json args{};
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}
