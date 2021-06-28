#pragma once

#ifdef _WIN32
#define DllExport   __declspec( dllexport )
#else
#define DllExport   /* Why windows is so weird and unpredictable */
#endif

extern "C" DllExport int GraphCATReset();
extern "C" DllExport int ChipConfigRegisterWrite(const unsigned in[3], unsigned out[3]);
extern "C" DllExport int PixelConfigRegisterWrite(const unsigned in[560], unsigned out[560]);
extern "C" DllExport int PixelPulseRegisterWrite(const unsigned in[35], unsigned out[35]);
extern "C" DllExport int GeneratePulses();
extern "C" DllExport int ReadTemperature(unsigned* temp);
extern "C" DllExport void initCommunication(const char* str, unsigned sync_port, unsigned async_port);
extern "C" DllExport int LnaHpfReset(unsigned wait_time_us);
extern "C" DllExport int LnaNeuronDriving(unsigned wait_time_us, unsigned reset_time_us, bool disable_reset = false);
extern "C" DllExport int LnaNoNeuronDriving(unsigned wait_time_us, unsigned reset_time_us, bool disable_reset = false);
extern "C" DllExport int PllOutResetStatus(unsigned* status);
extern "C" DllExport int PllBitStreamGenerator(unsigned mode);
extern "C" DllExport int LnaEnableCB(bool hpf_reset, bool lna_in_short, bool lna_in_en);
extern "C" DllExport int SetReadoutElectrode(unsigned n);
// neuron_driving == true -> LnaNeuronDriving is executed
// neuron_driving == false -> LnaNoNeuronDriving is executed
extern "C" DllExport int StartLnaThread(bool neuron_driving, unsigned period_ms, unsigned wait_time_us, unsigned reset_time_us,
										bool disable_reset = false);
extern "C" DllExport int StopThread();
