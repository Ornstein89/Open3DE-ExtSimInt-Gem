
#include <AzCore/Memory/Memory_fwd.h>
#include <AzCore/Module/Module.h>
#include <AzCore/RTTI/RTTIMacros.h>
#include <AzCore/RTTI/TypeInfoSimple.h>

#include <ReceiveMotionParamsComponent.h>
#include <TranslatePictureComponent.h>

namespace Open3DE_ExtSimInt_Gem
{
    class Open3DE_ExtSimInt_GemModuleInterface
        : public AZ::Module
    {
    public:
        AZ_TYPE_INFO_WITH_NAME_DECL(Open3DE_ExtSimInt_GemModuleInterface)
        AZ_RTTI_NO_TYPE_INFO_DECL()
        AZ_CLASS_ALLOCATOR_DECL

        Open3DE_ExtSimInt_GemModuleInterface();

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override;
    };
}// namespace Open3DE_ExtSimInt_Gem
