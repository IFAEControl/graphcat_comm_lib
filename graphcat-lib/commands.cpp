#ifdef _WIN32
#pragma once
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

#include "commands.hpp"

unsigned Temperature::getAnswer() {
    return m.body["answer"]["temperature"];
}


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
	Message c; return c;
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

Message CommandCreator::write_pixel_config(std::array<unsigned int, 560> pixel_config) {
    Message c;
    c.body["command"] = "gc.write_pixel_config";
    c.body["answer"] = json{};
    json args;
    args["pixel_config"] = pixel_config;
    c.body["arguments"] = args;
    auto buf = c.body.dump();

    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}


Message CommandCreator::pixel_pulse_write(std::array<unsigned, 35> pixel_pulse) {
    Message c;
    c.body["command"] = "gc.pixel_pulse_write";
    c.body["answer"] = json{};
    json args;
    args["pixel_pulse"] = pixel_pulse;
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Temperature CommandCreator::read_temperature() {
    Message c;
    c.body["command"] = "gc.read_temperature";
    c.body["answer"] = json{};
    c.body["arguments"] = json{};
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());

    return Temperature(c);
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

Message CommandCreator::reset_lna_hpf(unsigned wait_time_us) {
        Message c;
    c.body["command"] = "gc.reset_lna_hpf";
    c.body["answer"] = json{};
    json args;
    args["wait_time_us"] = wait_time_us;
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::lna_neuron_driving(unsigned wait_time_us) {
        Message c;
    c.body["command"] = "gc.lna_neuron_driving";
    c.body["answer"] = json{};
    json args;
    args["wait_time_us"] = wait_time_us;
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::lna_no_neuron_driving(unsigned wait_time_us) {
    Message c;
    c.body["command"] = "gc.lna_no_neuron_driving";
    c.body["answer"] = json{};
    json args;
    args["wait_time_us"] = wait_time_us;
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::get_pll_out_reset_status() {
    Message c;
    c.body["command"] = "gc.get_pll_out_reset_status";
    c.body["answer"] = json{};
    c.body["arguments"] = json{};
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}

Message CommandCreator::set_pll_bitstream_mode(unsigned mode) {
    Message c;
    c.body["command"] = "gc.set_pll_bitstream_mode";
    c.body["answer"] = json{};
    json args;
    args["mode"] = mode;
    c.body["arguments"] = args;
    auto buf = c.body.dump();
    
    c.header.packtype = HEADER_PACKTYPE::COMMAND;
    c.header.packetsize = htonl(buf.size());
    return c;
}
