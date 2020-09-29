#pragma once

#include <iostream>
#include <array>

#include <nlohmann/json.hpp>

#include "header.hpp"

using json = nlohmann::json;

struct Message {
    BaseHeaderType header{};
    json body{};
};

class CommandCreator {
public:
    Message ping_pong();
    Message reset();
    Message write_chip_config(std::array<unsigned, 3> chip_config);
    Message pixel_pulse_write();
    Message generate_pulse();
    Message read_temperature();
    Message read_reg();
    Message write_reg();
private:

};
