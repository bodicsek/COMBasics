// dllmain.h : Declaration of module class.

class CAtlComDllModule : public ATL::CAtlDllModuleT< CAtlComDllModule >
{
public :
	DECLARE_LIBID(LIBID_AtlComDllLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLCOMDLL, "{236EAE8B-E448-4BA0-94A2-A833CDB46976}")
};

extern class CAtlComDllModule _AtlModule;
