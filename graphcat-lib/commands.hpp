#pragma once

#include <iostream>

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
    Message pixel_pulse_write();
    Message generate_pulse();
    Message read_temperature();
    Message read_reg();
    Message write_reg();
private:

};
