
#include "Open3DE-ExtSimInt-GemSystemComponent.h"

#include <Open3DE-ExtSimInt-Gem/Open3DE-ExtSimInt-GemTypeIds.h>

#include <AzCore/Serialization/SerializeContext.h>

namespace Open3DE_ExtSimInt_Gem
{
    AZ_COMPONENT_IMPL(Open3DE_ExtSimInt_GemSystemComponent, "Open3DE_ExtSimInt_GemSystemComponent",
        Open3DE_ExtSimInt_GemSystemComponentTypeId);

    void Open3DE_ExtSimInt_GemSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<Open3DE_ExtSimInt_GemSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void Open3DE_ExtSimInt_GemSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("Open3DE_ExtSimInt_GemService"));
    }

    void Open3DE_ExtSimInt_GemSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("Open3DE_ExtSimInt_GemService"));
    }

    void Open3DE_ExtSimInt_GemSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void Open3DE_ExtSimInt_GemSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    Open3DE_ExtSimInt_GemSystemComponent::Open3DE_ExtSimInt_GemSystemComponent()
    {
        if (Open3DE_ExtSimInt_GemInterface::Get() == nullptr)
        {
            Open3DE_ExtSimInt_GemInterface::Register(this);
        }
    }

    Open3DE_ExtSimInt_GemSystemComponent::~Open3DE_ExtSimInt_GemSystemComponent()
    {
        if (Open3DE_ExtSimInt_GemInterface::Get() == this)
        {
            Open3DE_ExtSimInt_GemInterface::Unregister(this);
        }
    }

    void Open3DE_ExtSimInt_GemSystemComponent::Init()
    {
    }

    void Open3DE_ExtSimInt_GemSystemComponent::Activate()
    {
        Open3DE_ExtSimInt_GemRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void Open3DE_ExtSimInt_GemSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        Open3DE_ExtSimInt_GemRequestBus::Handler::BusDisconnect();
    }

    void Open3DE_ExtSimInt_GemSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace Open3DE_ExtSimInt_Gem
