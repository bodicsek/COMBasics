// BareboneComDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "BareboneComDll.h"
#include "Iid.h"
#include "ComponentClassFactory.h"

ULONG g_lockCount = 0;
ULONG g_objCount = 0;

extern "C" HRESULT __stdcall DllCanUnloadNow()
{
  if (g_lockCount == 0 && g_objCount == 0)
  {
    return S_OK;
  }
  else
  {
    return S_FALSE;
  }
}

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void ** ppAny)
{
  if (rclsid != CLSID_Component)
  {
    return CLASS_E_CLASSNOTAVAILABLE;
  }

  ComponentClassFactory * pFactory = new ComponentClassFactory();

  HRESULT hr = pFactory->QueryInterface(riid, ppAny);

  if (FAILED(hr))
  {
    delete pFactory;
  }

  return hr;
}
