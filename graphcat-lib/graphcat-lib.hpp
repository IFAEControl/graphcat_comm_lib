#pragma once

extern "C" int gc_ping_pong();

extern "C" int readReg();
extern "C" int GraphCATReset();
extern "C" int PixelPulseRegisterWrite(unsigned *pxPulseRegDatain[35], unsigned *pxPulseRegDataout[35]);
extern "C" int GeneratePulses();
extern "C" int ReadTemperature(unsigned* temp);
extern "C" void initCommunication(const char* str, unsigned sync_port, unsigned async_port);
