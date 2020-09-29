#ifdef _WIN32
#pragma once
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

#include "commands.hpp"

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

Message CommandCreator::read_reg() {
    Message c;
    c.body["command"] = "gc.read_reg";
    c.body["answer"] = json{};
    json args;
    args["reg"] = 0x1;
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::write_reg() {
}

Message CommandCreator::reset() {
    Message c;
    c.body["command"] = "gc.reset_gc_chip";
    c.body["answer"] = json{};
    json args{};
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::write_chip_config(std::array<unsigned, 3> chip_config) {
    Message c;
    c.body["command"] = "gc.write_chip_config";
    c.body["answer"] = json{};
    json args;
    args["chip_config"] = chip_config;
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
    c.body["arguments"] = json{};
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::generate_pulse() {
    Message c;
    c.body["command"] = "gc.generate_pulses";
    c.body["answer"] = json{};
    c.body["arguments"] = json{};
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}
