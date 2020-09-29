#pragma once

#ifdef _WIN32
#define DllExport   __declspec( dllexport )
#else
#define DllExport   /* Why windows is so weird and unpredictable */
#endif

extern "C" DllExport int gc_ping_pong();

extern "C" DllExport int readReg();
extern "C" DllExport int GraphCATReset();
extern "C" DllExport int ChipConfigRegisterWrite(const unsigned in[3], unsigned out[3]);
extern "C" DllExport int PixelPulseRegisterWrite(unsigned *pxPulseRegDatain[35], unsigned *pxPulseRegDataout[35]);
extern "C" DllExport int GeneratePulses();
extern "C" DllExport int ReadTemperature(unsigned* temp);
extern "C" DllExport void initCommunication(const char* str, unsigned sync_port, unsigned async_port);
