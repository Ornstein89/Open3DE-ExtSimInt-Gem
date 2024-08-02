
#include <Open3DE-ExtSimInt-Gem/Open3DE-ExtSimInt-GemTypeIds.h>
#include <Open3DE-ExtSimInt-GemModuleInterface.h>
#include "Open3DE-ExtSimInt-GemSystemComponent.h"

namespace Open3DE_ExtSimInt_Gem
{
    class Open3DE_ExtSimInt_GemModule
        : public Open3DE_ExtSimInt_GemModuleInterface
    {
    public:
        AZ_RTTI(Open3DE_ExtSimInt_GemModule, Open3DE_ExtSimInt_GemModuleTypeId, Open3DE_ExtSimInt_GemModuleInterface);
        AZ_CLASS_ALLOCATOR(Open3DE_ExtSimInt_GemModule, AZ::SystemAllocator);
    };
}// namespace Open3DE_ExtSimInt_Gem

AZ_DECLARE_MODULE_CLASS(Gem_Open3DE_ExtSimInt_Gem, Open3DE_ExtSimInt_Gem::Open3DE_ExtSimInt_GemModule)
