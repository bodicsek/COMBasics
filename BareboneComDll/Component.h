#pragma once
#include "Interface.h"

class Component : public IKnowledgeBase
{
public:
  Component();
  virtual ~Component();

  STDMETHODIMP QueryInterface(REFIID riid, void ** ppAny);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  STDMETHODIMP Answer(BYTE* pnResult);

private:
  ULONG m_refCount;
};

