#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/RTTI/BehaviorContext.h>
#include <AzCore/Component/EntityId.h>
#include <AzFramework/Entity/EntityDebugDisplayBus.h>
#include <AzCore/Component/TransformBus.h>

#include <ReceiveMotionParamsComponent.h>

namespace Open3DE_ExtSimInt_Gem
{
    // AZ_COMPONENT_IMPL(ReceiveMotionParamsComponent, "ReceiveMotionParamsComponent", "{354FA199-B691-4136-864A-BA78D443D89D}");

    void ReceiveMotionParamsComponent::Activate()
    {
        m_time = AZ::ScriptTimePoint(AZStd::chrono::steady_clock::now() );
        ReceiveMotionParamsRequestBus::Handler::BusConnect(GetEntityId());

        AZ::TickBus::Handler::BusConnect();
        // AzFramework::EntityDebugDisplayEventBus::Handler::BusConnect(GetEntityId());

        AzFramework::EntityDebugDisplayEventBus::Handler::BusConnect(GetEntityId());

        
    }

    void ReceiveMotionParamsComponent::Deactivate()
    {
        ReceiveMotionParamsRequestBus::Handler::BusDisconnect(GetEntityId());

        AZ::TickBus::Handler::BusDisconnect();
        AzFramework::EntityDebugDisplayEventBus::Handler::BusDisconnect();
    }

    void ReceiveMotionParamsComponent::Reflect(AZ::ReflectContext *context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext *>(context))
        {
            serializeContext->Class<ReceiveMotionParamsComponent, AZ::Component>()
                ->Version(1);

            if (AZ::EditContext *editContext = serializeContext->GetEditContext())
            {
                editContext->Class<ReceiveMotionParamsComponent>("ReceiveMotionParamsComponent", "[Description of functionality provided by this component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    ->Attribute(AZ::Edit::Attributes::Category, "ComponentCategory")
                    ->Attribute(AZ::Edit::Attributes::Icon, "Icons/Components/Component_Placeholder.svg")
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC_CE("Game"));
            }
        }

        if (AZ::BehaviorContext *behaviorContext = azrtti_cast<AZ::BehaviorContext *>(context))
        {
            behaviorContext->Class<ReceiveMotionParamsComponent>("ReceiveMotionParams Component Group")
                ->Attribute(AZ::Script::Attributes::Category, "Open3DE-ExtSimInt-Gem Gem Group");
        }
    }

    void ReceiveMotionParamsComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType &provided)
    {
        provided.push_back(AZ_CRC_CE("ReceiveMotionParamsComponentService"));
    }

    void ReceiveMotionParamsComponent::GetIncompatibleServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType &incompatible)
    {
    }

    void ReceiveMotionParamsComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType &required)
    {
    }

    void ReceiveMotionParamsComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType &dependent)
    {
    }

    void ReceiveMotionParamsComponent::OnTick(
        [[maybe_unused]] float deltaTime,
        [[maybe_unused]] AZ::ScriptTimePoint time)
    {
        // debugDisplay.SetColor(AZ::Colors::Red);
        // debugDisplay.Draw2dTextLabel(25.0f, 25.0f, 1.0f, "Hello, O3DE 25 25!");
        m_time = AZ::ScriptTimePoint(time.Get());
        float phase = float(remainder((m_time.GetMilliseconds() / 1.0e+03f), 2.0 * M_PI)); 
        AZ::Vector3 position(float(AZStd::sin(phase))*10.0f, float(AZStd::cos(phase))*10.0f, 100.0f);
        // https://docs.o3de.org/docs/user-guide/programming/messaging/ebus/
        // https://docs.o3de.org/docs/user-guide/components/reference/transform/
        AZ::TransformBus::Event(GetEntityId(), &AZ::TransformBus::Events::SetWorldTranslation, position);
        return;
    }


    void ReceiveMotionParamsComponent::DisplayEntityViewport(
        [[maybe_unused]] const AzFramework::ViewportInfo& viewportInfo,
        AzFramework::DebugDisplayRequests& debugDisplay)
    {
        // Set the color and draw the text
        // AZStd::string m_textToDisplay = "Hello, O3DE 1!";
        debugDisplay.SetColor(AZ::Colors::Blue);
        // // debugDisplay.DrawTextLabel(AZ::Vector3::CreateZero(), 1.0f, "Hello, O3DE! 0 0 0");
        // // debugDisplay.DrawTextLabel(AZ::Vector3(10.0f, 10.0f, 10.0f), 1.0f, "Hello, O3DE! 10 10 10");
        // const char * timeString = AZ::ScriptTimePoint( AZStd::chrono::steady_clock::now() ).ToString().c_str();
        const char * timeString = m_time.ToString().c_str();
        debugDisplay.Draw2dTextLabel(25.0f, 25.0f, 1.0f, timeString);
        debugDisplay.SetColor(AZ::Colors::Red);
        debugDisplay.Draw2dTextLabel(26.0f, 26.0f, 1.0f, timeString);
    }
} // namespace Open3DE_ExtSimInt_Gem
