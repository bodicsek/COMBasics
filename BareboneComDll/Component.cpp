#include "stdafx.h"
#include "Component.h"
#include "Iid.h"

extern ULONG g_lockCount;
extern ULONG g_objCount;

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
    // to avoid confusion caused by virtual inheritance
    *ppAny = (IUnknown *)(IKnowledgeBase *)this;
  }
  else if (riid == IID_IKnowledgeBase)
  {
    *ppAny = (IKnowledgeBase *)this;
  }
  else
  {
    *ppAny = NULL;
    return E_NOINTERFACE;
  }

  ((IUnknown *)(*ppAny))->AddRef();

  return S_OK;
}

STDMETHODIMP Component::Answer(BYTE* pnResult)
{
  *pnResult = 42;
  return S_OK;
}