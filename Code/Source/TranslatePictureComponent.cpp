
#include <TranslatePictureComponent.h>

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/RTTI/BehaviorContext.h>

namespace Open3DE_ExtSimInt_Gem
{
    // AZ_COMPONENT_IMPL(TranslatePictureComponent, "TranslatePictureComponent", "{F177E831-C499-4C7B-B509-1CFB42633519}");

    void TranslatePictureComponent::Activate()
    {
        TranslatePictureRequestBus::Handler::BusConnect(GetEntityId());
    }

    void TranslatePictureComponent::Deactivate()
    {
        TranslatePictureRequestBus::Handler::BusDisconnect(GetEntityId());
    }

    void TranslatePictureComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<TranslatePictureComponent, AZ::Component>()
                ->Version(1)
                ;

            if (AZ::EditContext* editContext = serializeContext->GetEditContext())
            {
                editContext->Class<TranslatePictureComponent>("TranslatePictureComponent", "[Description of functionality provided by this component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    ->Attribute(AZ::Edit::Attributes::Category, "ComponentCategory")
                    ->Attribute(AZ::Edit::Attributes::Icon, "Icons/Components/Component_Placeholder.svg")
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC_CE("Game"))
                    ;
            }
        }

        if (AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
        {
            behaviorContext->Class<TranslatePictureComponent>("TranslatePicture Component Group")
                ->Attribute(AZ::Script::Attributes::Category, "Open3DE-ExtSimInt-Gem Gem Group")
                ;
        }
    }

    void TranslatePictureComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("TranslatePictureComponentService"));
    }

    void TranslatePictureComponent::GetIncompatibleServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
    }

    void TranslatePictureComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void TranslatePictureComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
} // namespace Open3DE_ExtSimInt_Gem
