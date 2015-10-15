#ifndef INTERFACE_H
#define INTERFACE_H

#include <unknwn.h>

struct IKnowledgeBase : public IUnknown
{
    virtual HRESULT __stdcall Answer(BYTE* pnResult) = 0;
};

#endif //INTERFACE_H
