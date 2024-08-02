
#pragma once

namespace Open3DE_ExtSimInt_Gem
{
    // System Component TypeIds
    inline constexpr const char* Open3DE_ExtSimInt_GemSystemComponentTypeId = "{D5650AB0-C2F3-481A-9E63-C741DB8D76E0}";
    inline constexpr const char* Open3DE_ExtSimInt_GemEditorSystemComponentTypeId = "{004AA9DB-B513-401A-8033-0A16D3B28EE3}";

    // Module derived classes TypeIds
    inline constexpr const char* Open3DE_ExtSimInt_GemModuleInterfaceTypeId = "{CFB655CD-B0DD-4D6A-B619-C84DD82E87BB}";
    inline constexpr const char* Open3DE_ExtSimInt_GemModuleTypeId = "{85F9B906-015D-45C4-B03C-CB2A084E6C65}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* Open3DE_ExtSimInt_GemEditorModuleTypeId = Open3DE_ExtSimInt_GemModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* Open3DE_ExtSimInt_GemRequestsTypeId = "{9540490A-4CFD-48CE-9079-BB43DFE58A33}";
} // namespace Open3DE_ExtSimInt_Gem
