#include "stdafx.h"
#include "Component.h"
#include "Iid.h"

extern ULONG g_lockCount; //global COM locks on the DLL
extern ULONG g_objCount;  //number of objects created by the DLL

Component::Component()
{
  m_refCount = 0;
  ++g_objCount;
}

Component::~Component()
{
  --g_objCount;
}

STDMETHODIMP_(ULONG) Component::AddRef()
{
  return ++m_refCount;
}

STDMETHODIMP_(ULONG) Component::Release()
{
  if (--m_refCount == 0)
  {
    delete this;
    return 0;
  }
  else
  {
    return m_refCount;
  }
}

STDMETHODIMP Component::QueryInterface(REFIID riid, void ** ppAny)
{
  // IID_IUnknown is the REFIID of standard interface IUnknown
  if (riid == IID_IUnknown)
  {
    *ppAny = (IUnknown*)this;
  }
  // IID_IKnowledgeBase is the REFIID of our interface defined in Iid.h
  else if (riid == IID_IKnowledgeBase)
  {
    *ppAny = (IKnowledgeBase*)this;
  }
  else
  {
    *ppAny = NULL;
    return E_NOINTERFACE;
  }

  //Default reference increment
  ((IUnknown *)(*ppAny))->AddRef();

  return S_OK;
}

STDMETHODIMP Component::Answer(BYTE* pnResult)
{
  *pnResult = 42;
  return S_OK;
}