
#include "Open3DE-ExtSimInt-GemModuleInterface.h"
#include <AzCore/Memory/Memory.h>

#include <Open3DE-ExtSimInt-Gem/Open3DE-ExtSimInt-GemTypeIds.h>

#include <Clients/Open3DE-ExtSimInt-GemSystemComponent.h>

namespace Open3DE_ExtSimInt_Gem
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(Open3DE_ExtSimInt_GemModuleInterface,
        "Open3DE_ExtSimInt_GemModuleInterface", Open3DE_ExtSimInt_GemModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(Open3DE_ExtSimInt_GemModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(Open3DE_ExtSimInt_GemModuleInterface, AZ::SystemAllocator);

    Open3DE_ExtSimInt_GemModuleInterface::Open3DE_ExtSimInt_GemModuleInterface()
    {
        // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
        // Add ALL components descriptors associated with this gem to m_descriptors.
        // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
        // This happens through the [MyComponent]::Reflect() function.
        m_descriptors.insert(m_descriptors.end(), {
            Open3DE_ExtSimInt_GemSystemComponent::CreateDescriptor(),
            Open3DE_ExtSimInt_Gem::ReceiveMotionParamsComponent::CreateDescriptor(),
            Open3DE_ExtSimInt_Gem::TranslatePictureComponent::CreateDescriptor()
            });
    }

    AZ::ComponentTypeList Open3DE_ExtSimInt_GemModuleInterface::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<Open3DE_ExtSimInt_GemSystemComponent>(),
        };
    }
} // namespace Open3DE_ExtSimInt_Gem
