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
private:

};
