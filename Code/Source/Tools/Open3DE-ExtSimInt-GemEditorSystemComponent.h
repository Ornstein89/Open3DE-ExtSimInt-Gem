
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/Open3DE-ExtSimInt-GemSystemComponent.h>

namespace Open3DE_ExtSimInt_Gem
{
    /// System component for Open3DE_ExtSimInt_Gem editor
    class Open3DE_ExtSimInt_GemEditorSystemComponent
        : public Open3DE_ExtSimInt_GemSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = Open3DE_ExtSimInt_GemSystemComponent;
    public:
        AZ_COMPONENT_DECL(Open3DE_ExtSimInt_GemEditorSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        Open3DE_ExtSimInt_GemEditorSystemComponent();
        ~Open3DE_ExtSimInt_GemEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace Open3DE_ExtSimInt_Gem
