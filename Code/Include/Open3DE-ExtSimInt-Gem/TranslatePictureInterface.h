
#pragma once

#include <AzCore/Component/ComponentBus.h>

namespace Open3DE_ExtSimInt_Gem
{
    class TranslatePictureRequests
        : public AZ::ComponentBus
    {
    public:
        AZ_RTTI(Open3DE_ExtSimInt_Gem::TranslatePictureRequests, "{1802EC12-33FE-4543-80B1-07612887E760}");

        // Put your public request methods here.
        
        // Put notification events here. Examples:
        // void RegisterEvent(AZ::EventHandler<...> notifyHandler);
        // AZ::Event<...> m_notifyEvent1;
        
    };

    using TranslatePictureRequestBus = AZ::EBus<TranslatePictureRequests>;

} // namespace Open3DE_ExtSimInt_Gem
