// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Interface.h"
#include "Iid.h"

//#include <atlbase.h>
//#import "../Debug/AtlComDll.dll" no_namespace named_guids raw_interfaces_only

int main()
{
  CoInitialize(NULL);

  IClassFactory* pClassFactory = NULL;
  HRESULT hr = CoGetClassObject(CLSID_Component1, CLSCTX_SERVER, NULL, IID_IClassFactory, (void**)&pClassFactory);
  if (FAILED(hr))
  {
    std::cout << "CoGetClassObject failed!" << std::endl;
    return 1;
  }

  IKnowledgeBase* pKb = NULL;
  hr = pClassFactory->CreateInstance(NULL, IID_IKnowledgeBase, (void**)&pKb);
  pClassFactory->Release();
  if (FAILED(hr))
  {
    std::cout << "CreateInstance failed!" << std::endl;
    return 2;
  }

  byte theAnswer = 0;
  hr = pKb->Answer(&theAnswer);
  pKb->Release();
  if (FAILED(hr))
  {
    std::cout << "Answer failed!" << std::endl;
    return 3;
  }

  std::cout << "The ultimate answer is: " << theAnswer << std::endl;

  CoUninitialize();

  return 0;
}


//int main(int argc, char* argv[])
//{
//  CoInitialize(NULL);
//
//  IKnowledgeBase* pKb = NULL;
//  HRESULT hr = CoCreateInstance(CLSID_Component, NULL, CLSCTX_INPROC_SERVER, IID_IKnowledgeBase, (void**)&pKb);
//  if (FAILED(hr))
//  {
//    std::cout << "CoCreateInstance failed!" << std::endl;
//    return 1;
//  }
//
//  byte bResult = 0;
//  hr = pKb->Answer(&bResult);
//  pKb->Release();
//
//  CoUninitialize();
//
//  return 0;
//}

//int main(int argc, char* argv[])
//{
//  CoInitialize(NULL);
//
//  {
//    CComPtr<IKnowledgeBase> pKb;
//    HRESULT hr = pKb.CoCreateInstance(CLSID_Component1);
//    if (FAILED(hr))
//    {
//      std::cout << "CComPtr CoCreateInstance failed!";
//      return 1;
//    }
//
//    BYTE bResult;
//    hr = pKb->Answer(&bResult);
//  }
//
//  CoUninitialize();
//  return 0;
//}
