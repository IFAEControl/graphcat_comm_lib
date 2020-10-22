#include <array>

#ifdef _WIN32
#pragma once
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

#include "commands.hpp"

std::ostream& operator<<(std::ostream& stream, const Command& c) {
    stream << c.m.body;
    return stream;
}

Temperature::Temperature() {
    m.body["command"] = "gc.read_temperature";
    m.body["answer"] = json{};
    m.body["arguments"] = json{};
    auto buf = m.body.dump();
    
    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}

unsigned Temperature::getAnswer() {
    return m.body["answer"]["temperature"];
}

WriteChipConfig::WriteChipConfig(uint96_t& cfg) {
    m.body["command"] = "gc.write_chip_config";
    m.body["answer"] = json{};
    json args;
    args["chip_config"] = cfg.val();
    m.body["arguments"] = args;
    auto buf = m.body.dump();
    
    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}

uint96_t WriteChipConfig::getAnswer() {
    return m.body["answer"]["chip_config"];
}


WritePixelConfig::WritePixelConfig(uint17920_t& cfg) {
    m.body["command"] = "gc.write_pixel_config";
    m.body["answer"] = json{};
    json args;
    args["pixel_config"] = cfg.val();
    m.body["arguments"] = args;
    auto buf = m.body.dump();

    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}

uint17920_t WritePixelConfig::getAnswer() {
     return m.body["answer"]["pixel_config"];
}

PixelPulseWrite::PixelPulseWrite(uint1120_t& cfg) {
    m.body["command"] = "gc.pixel_pulse_write";
    m.body["answer"] = json{};
    json args;
    args["pixel_pulse"] = cfg.val();
    m.body["arguments"] = args;
    auto buf = m.body.dump();
    
    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}

uint1120_t PixelPulseWrite::getAnswer() {
    return m.body["answer"]["pixel_pulse"];
}

GCATReset::GCATReset() {
    m.body["command"] = "gc.reset_gc_chip";
    m.body["answer"] = json{};
    json args{};
    m.body["arguments"] = args;
    auto buf = m.body.dump();
    
    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}

PulsesGenerate::PulsesGenerate() {
    m.body["command"] = "gc.generate_pulses";
    m.body["answer"] = json{};
    m.body["arguments"] = json{};
    auto buf = m.body.dump();
    
    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}

ResetLnaHpf::ResetLnaHpf(unsigned wait_time_us) {
    m.body["command"] = "gc.reset_lna_hpf";
    m.body["answer"] = json{};
    json args;
    args["wait_time_us"] = wait_time_us;
    m.body["arguments"] = args;
    auto buf = m.body.dump();
    
    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}

NeuronDrivingLna::NeuronDrivingLna(unsigned wait_time_us) {
    m.body["command"] = "gc.lna_neuron_driving";
    m.body["answer"] = json{};
    json args;
    args["wait_time_us"] = wait_time_us;
    m.body["arguments"] = args;
    auto buf = m.body.dump();
    
    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}

NoNeuronDrivingLna::NoNeuronDrivingLna(unsigned wait_time_us) {
    m.body["command"] = "gc.lna_no_neuron_driving";
    m.body["answer"] = json{};
    json args;
    args["wait_time_us"] = wait_time_us;
    m.body["arguments"] = args;
    auto buf = m.body.dump();
    
    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}

StatusPllOutReset::StatusPllOutReset() {
    m.body["command"] = "gc.get_pll_out_reset_status";
    m.body["answer"] = json{};
    m.body["arguments"] = json{};
    auto buf = m.body.dump();
    
    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}

unsigned StatusPllOutReset::getAnswer() {
    return m.body["answer"]["status"];
}

ModePllBitstream::ModePllBitstream(unsigned mode) {
    m.body["command"] = "gc.set_pll_bitstream_mode";
    m.body["answer"] = json{};
    json args;
    args["mode"] = mode;
    m.body["arguments"] = args;
    auto buf = m.body.dump();
    
    m.header.packtype = HEADER_PACKTYPE::COMMAND;
    m.header.packetsize = htonl(buf.size());
}
