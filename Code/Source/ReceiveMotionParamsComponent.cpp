
#include <ReceiveMotionParamsComponent.h>

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/RTTI/BehaviorContext.h>

namespace Open3DE_ExtSimInt_Gem
{
    // AZ_COMPONENT_IMPL(ReceiveMotionParamsComponent, "ReceiveMotionParamsComponent", "{354FA199-B691-4136-864A-BA78D443D89D}");

    void ReceiveMotionParamsComponent::Activate()
    {
        ReceiveMotionParamsRequestBus::Handler::BusConnect(GetEntityId());
    }

    void ReceiveMotionParamsComponent::Deactivate()
    {
        ReceiveMotionParamsRequestBus::Handler::BusDisconnect(GetEntityId());
    }

    void ReceiveMotionParamsComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<ReceiveMotionParamsComponent, AZ::Component>()
                ->Version(1)
                ;

            if (AZ::EditContext* editContext = serializeContext->GetEditContext())
            {
                editContext->Class<ReceiveMotionParamsComponent>("ReceiveMotionParamsComponent", "[Description of functionality provided by this component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    ->Attribute(AZ::Edit::Attributes::Category, "ComponentCategory")
                    ->Attribute(AZ::Edit::Attributes::Icon, "Icons/Components/Component_Placeholder.svg")
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC_CE("Game"))
                    ;
            }
        }

        if (AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
        {
            behaviorContext->Class<ReceiveMotionParamsComponent>("ReceiveMotionParams Component Group")
                ->Attribute(AZ::Script::Attributes::Category, "Open3DE-ExtSimInt-Gem Gem Group")
                ;
        }
    }

    void ReceiveMotionParamsComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("ReceiveMotionParamsComponentService"));
    }

    void ReceiveMotionParamsComponent::GetIncompatibleServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
    }

    void ReceiveMotionParamsComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void ReceiveMotionParamsComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
} // namespace Open3DE_ExtSimInt_Gem
