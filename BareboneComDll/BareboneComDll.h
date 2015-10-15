// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BAREBONECOMDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BAREBONECOMDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BAREBONECOMDLL_EXPORTS
#define BAREBONECOMDLL_API __declspec(dllexport)
#else
#define BAREBONECOMDLL_API __declspec(dllimport)
#endif

extern "C" HRESULT __stdcall DllCanUnloadNow();

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void ** ppAny);
