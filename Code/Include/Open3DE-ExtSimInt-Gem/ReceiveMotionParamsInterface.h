
#pragma once

#include <AzCore/Component/ComponentBus.h>

namespace Open3DE_ExtSimInt_Gem
{
    class ReceiveMotionParamsRequests
        : public AZ::ComponentBus
    {
    public:
        AZ_RTTI(Open3DE_ExtSimInt_Gem::ReceiveMotionParamsRequests, "{B6122EB3-7E1A-4AC5-9AB7-16BDA0A1F653}");

        // Put your public request methods here.
        
        // Put notification events here. Examples:
        // void RegisterEvent(AZ::EventHandler<...> notifyHandler);
        // AZ::Event<...> m_notifyEvent1;
        
    };

    using ReceiveMotionParamsRequestBus = AZ::EBus<ReceiveMotionParamsRequests>;

} // namespace Open3DE_ExtSimInt_Gem
