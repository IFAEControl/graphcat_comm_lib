#include "graphcat-lib.hpp"

int main() {
    initCommunication("127.0.0.1", 32000, 32001);
    gc_ping_pong();
}
