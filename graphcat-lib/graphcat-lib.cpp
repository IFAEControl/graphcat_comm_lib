#include <iostream>
#include <array>
#include <algorithm>

#include "graphcat-lib.hpp"
#include "commands.hpp"
#include "sockets.hpp"

int GraphCATReset() try {
    GCATReset cmd;
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int ChipConfigRegisterWrite(const unsigned in[3], unsigned out[3]) try {
    uint96_t chip_config = in;
    WriteChipConfig cmd(chip_config);
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    auto out_arr = resp.getAnswer();
    std::copy(out_arr.begin(), out_arr.end(), out);
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int PixelConfigRegisterWrite(const unsigned in[560], unsigned out[560]) try {
    uint17920_t pixel_config = in;
    WritePixelConfig cmd(pixel_config);
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    auto out_arr = resp.getAnswer();
    std::copy(out_arr.begin(), out_arr.end(), out);
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int PixelPulseRegisterWrite(const unsigned in[35], unsigned out[35]) try {
    uint1120_t pixel_pulse = in;
    PixelPulseWrite cmd(pixel_pulse);
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    auto out_arr = resp.getAnswer();
    std::copy(out_arr.begin(), out_arr.end(), out);
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}


int GeneratePulses() try {
    PulsesGenerate cmd;
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int ReadTemperature(unsigned* temp) try {
    if(!temp)
        return -1;

    Temperature cmd;
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    *temp = resp.getAnswer();
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

void initCommunication(const char* str, unsigned sync_port, unsigned async_port) {
    set_dest_ip(str);
}

int LnaHpfReset(unsigned wait_time_us) try {
    ResetLnaHpf cmd(wait_time_us);
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int LnaNeuronDriving(unsigned wait_time_us) try {
    NeuronDrivingLna cmd(wait_time_us);
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int LnaNoNeuronDriving(unsigned wait_time_us) try {
    NoNeuronDrivingLna cmd(wait_time_us);
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int PllOutResetStatus(unsigned* status) try {
    if(!status)
        return -1;
    
    StatusPllOutReset cmd;
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    *status = resp.getAnswer();
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int PllBitStreamGenerator(unsigned mode) try {
    ModePllBitstream cmd(mode);
    auto resp = send_command(cmd);
    std::cout << resp << std::endl;
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}
