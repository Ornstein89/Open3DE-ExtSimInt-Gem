
#pragma once

#include <AzCore/Component/Component.h>
#include <AzCore/Component/TickBus.h>
#include <Open3DE-ExtSimInt-Gem/Open3DE-ExtSimInt-GemBus.h>

namespace Open3DE_ExtSimInt_Gem
{
    class Open3DE_ExtSimInt_GemSystemComponent
        : public AZ::Component
        , protected Open3DE_ExtSimInt_GemRequestBus::Handler
        , public AZ::TickBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(Open3DE_ExtSimInt_GemSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        Open3DE_ExtSimInt_GemSystemComponent();
        ~Open3DE_ExtSimInt_GemSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // Open3DE_ExtSimInt_GemRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZTickBus interface implementation
        void OnTick(float deltaTime, AZ::ScriptTimePoint time) override;
        ////////////////////////////////////////////////////////////////////////
    };

} // namespace Open3DE_ExtSimInt_Gem
