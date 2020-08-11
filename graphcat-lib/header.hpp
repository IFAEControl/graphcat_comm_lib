#pragma once

#include <ostream>
#include <cstdint>

constexpr uint8_t HEADER_BYTE_SIZE = 32;

// FIXME: windows compilation error
//enum class HEADER_PACKTYPE : uint8_t {
enum HEADER_PACKTYPE {
    COMMAND = 1,
    ASYNC_START_CDA,
    ASYNC_STOP_CDA,
    ASYNC_CDA_DATA,
    ERROR = 10,
};

/// @brief Packet meta-data
struct BaseHeaderType {
    // There is a total of 32 bytes
    // Check
    // http://stackoverflow.com/questions/7970383/extra-bytes-when-declaring-a-member-of-a-struct-as-uint32-t
    /*
     * Structs are padded to be an integer multiple of 4 bytes1 so that they
     * are
     * word-aligned.
     * http://en.wikipedia.org/wiki/Data_structure_alignment#Data_structure_padding
     *
     */
    HEADER_PACKTYPE packtype;
    uint8_t data_rate;
    uint8_t reserved[2];
    uint32_t packetsize;
    uint8_t fill[24];
    
    friend std::ostream &operator<<(std::ostream &output, const BaseHeaderType &h) { 
         output << static_cast<uint8_t>(h.packtype) << h.data_rate << h.reserved << h.packetsize << h.fill;
         return output;            
      }
};
