// Component1.h : Declaration of the Component1

#pragma once
#include "resource.h"       // main symbols
#include "AtlComDll_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

// Component1
class ATL_NO_VTABLE Component1 :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<Component1, &CLSID_Component1>,
  public IKnowledgeBase
{
public:
  Component1()
  {
  }

  DECLARE_REGISTRY_RESOURCEID(IDR_COMPONENT1)

  DECLARE_NOT_AGGREGATABLE(Component1)

  BEGIN_COM_MAP(Component1)
    COM_INTERFACE_ENTRY(IKnowledgeBase)
  END_COM_MAP()

  DECLARE_PROTECT_FINAL_CONSTRUCT()

  HRESULT FinalConstruct()
  {
    return S_OK;
  }

  void FinalRelease()
  {
  }

public:
  HRESULT STDMETHODCALLTYPE Answer(
    /* [out] */ BYTE *pbResult)
  {
    *pbResult = 42;
    return S_OK;
  }
};

OBJECT_ENTRY_AUTO(__uuidof(Component1), Component1)
