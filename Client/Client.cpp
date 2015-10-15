// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Interface.h"
#include "Iid.h"

/*
int main()
{
  CoInitialize(NULL);

  IClassFactory* pClassFactory = NULL;
  HRESULT hr = CoGetClassObject(CLSID_Component, CLSCTX_SERVER, NULL, IID_IClassFactory, (void**)&pClassFactory);
  if (FAILED(hr))
  {
    std::cout << "CoGetClassObject failed!" << std::endl;
    return 1;
  }

  IKnowledgeBase* pKb = NULL;
  hr = pClassFactory->CreateInstance(NULL, IID_IKnowledgeBase, (void**)&pKb);
  if (FAILED(hr))
  {
    std::cout << "CreateInstance failed!" << std::endl;
    return 2;
  }
  pClassFactory->Release();

  byte theAnswer = 0;
  hr = pKb->Answer(&theAnswer);
  if (FAILED(hr))
  {
    std::cout << "Answer failed!" << std::endl;
    return 3;
  }
  pKb->Release();

  std::cout << "THe ultimate answer is: " << theAnswer << std::endl;

  return 0;
}
*/
/*
int main(int argc, char* argv[])
{
  CoInitialize(NULL);

  IKnowledgeBase* pKb = NULL;
  HRESULT hr = CoCreateInstance(CLSID_Component, NULL, CLSCTX_INPROC_SERVER, IID_IKnowledgeBase, (void**)&pKb);
  if (FAILED(hr))
  {
    std::cout << "CoCreateInstance failed!" << std::endl;
    return 1;
  }

  byte bResult = 0;
  hr = pKb->Answer(&bResult);

  pKb->Release();

  return 0;
}
*/

#import "../Debug/DotNetComDll.tlb" no_namespace, raw_interfaces_only

int main(int argc, char* argv[])
{
  CoInitialize(NULL);
  return 0;
}