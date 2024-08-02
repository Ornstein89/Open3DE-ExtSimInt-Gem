
#include <AzCore/Serialization/SerializeContext.h>
#include "Open3DE-ExtSimInt-GemEditorSystemComponent.h"

#include <Open3DE-ExtSimInt-Gem/Open3DE-ExtSimInt-GemTypeIds.h>

namespace Open3DE_ExtSimInt_Gem
{
    AZ_COMPONENT_IMPL(Open3DE_ExtSimInt_GemEditorSystemComponent, "Open3DE_ExtSimInt_GemEditorSystemComponent",
        Open3DE_ExtSimInt_GemEditorSystemComponentTypeId, BaseSystemComponent);

    void Open3DE_ExtSimInt_GemEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<Open3DE_ExtSimInt_GemEditorSystemComponent, Open3DE_ExtSimInt_GemSystemComponent>()
                ->Version(0);
        }
    }

    Open3DE_ExtSimInt_GemEditorSystemComponent::Open3DE_ExtSimInt_GemEditorSystemComponent() = default;

    Open3DE_ExtSimInt_GemEditorSystemComponent::~Open3DE_ExtSimInt_GemEditorSystemComponent() = default;

    void Open3DE_ExtSimInt_GemEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("Open3DE_ExtSimInt_GemEditorService"));
    }

    void Open3DE_ExtSimInt_GemEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("Open3DE_ExtSimInt_GemEditorService"));
    }

    void Open3DE_ExtSimInt_GemEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void Open3DE_ExtSimInt_GemEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void Open3DE_ExtSimInt_GemEditorSystemComponent::Activate()
    {
        Open3DE_ExtSimInt_GemSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void Open3DE_ExtSimInt_GemEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        Open3DE_ExtSimInt_GemSystemComponent::Deactivate();
    }

} // namespace Open3DE_ExtSimInt_Gem
