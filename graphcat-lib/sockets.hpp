#pragma once

#include <nlohmann/json.hpp>

#include "commands.hpp"
#include "header.hpp"

Message send_command(const Message& c);
void set_dest_ip(const std::string& ip) noexcept;
