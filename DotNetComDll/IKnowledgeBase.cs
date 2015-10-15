using System.Runtime.InteropServices;

namespace DotNetComDll
{
  [Guid("6CDBC8F4-F901-4CA7-B582-F50E61A6D1AE")]
  [InterfaceType(ComInterfaceType.InterfaceIsDual)]
  public interface IKnowledgeBase
  {
    byte Answer();
  }
}
