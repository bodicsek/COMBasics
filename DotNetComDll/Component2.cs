using System.Runtime.InteropServices;

namespace DotNetComDll
{
  [Guid("34C039CB-E314-4D81-8A00-C6A61814DFAA")]
  [ComSourceInterfaces(typeof(IKnowledgeBase))]
  [ClassInterface(ClassInterfaceType.AutoDual)]  
  public class Component2 : IKnowledgeBase
  {
    public Component2()
    {
    }

    public byte Answer()
    {
      return 42;
    }
  }
}
