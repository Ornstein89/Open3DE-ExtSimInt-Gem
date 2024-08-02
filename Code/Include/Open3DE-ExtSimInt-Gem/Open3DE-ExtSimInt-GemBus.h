
#pragma once

#include <Open3DE-ExtSimInt-Gem/Open3DE-ExtSimInt-GemTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Open3DE_ExtSimInt_Gem
{
    class Open3DE_ExtSimInt_GemRequests
    {
    public:
        AZ_RTTI(Open3DE_ExtSimInt_GemRequests, Open3DE_ExtSimInt_GemRequestsTypeId);
        virtual ~Open3DE_ExtSimInt_GemRequests() = default;
        // Put your public methods here
    };

    class Open3DE_ExtSimInt_GemBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using Open3DE_ExtSimInt_GemRequestBus = AZ::EBus<Open3DE_ExtSimInt_GemRequests, Open3DE_ExtSimInt_GemBusTraits>;
    using Open3DE_ExtSimInt_GemInterface = AZ::Interface<Open3DE_ExtSimInt_GemRequests>;

} // namespace Open3DE_ExtSimInt_Gem
