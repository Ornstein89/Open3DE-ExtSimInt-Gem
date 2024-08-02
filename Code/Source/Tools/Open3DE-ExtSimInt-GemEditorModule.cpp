
#include <Open3DE-ExtSimInt-Gem/Open3DE-ExtSimInt-GemTypeIds.h>
#include <Open3DE-ExtSimInt-GemModuleInterface.h>
#include "Open3DE-ExtSimInt-GemEditorSystemComponent.h"

namespace Open3DE_ExtSimInt_Gem
{
    class Open3DE_ExtSimInt_GemEditorModule
        : public Open3DE_ExtSimInt_GemModuleInterface
    {
    public:
        AZ_RTTI(Open3DE_ExtSimInt_GemEditorModule, Open3DE_ExtSimInt_GemEditorModuleTypeId, Open3DE_ExtSimInt_GemModuleInterface);
        AZ_CLASS_ALLOCATOR(Open3DE_ExtSimInt_GemEditorModule, AZ::SystemAllocator);

        Open3DE_ExtSimInt_GemEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                Open3DE_ExtSimInt_GemEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<Open3DE_ExtSimInt_GemEditorSystemComponent>(),
            };
        }
    };
}// namespace Open3DE_ExtSimInt_Gem

AZ_DECLARE_MODULE_CLASS(Gem_Open3DE_ExtSimInt_Gem, Open3DE_ExtSimInt_Gem::Open3DE_ExtSimInt_GemEditorModule)
