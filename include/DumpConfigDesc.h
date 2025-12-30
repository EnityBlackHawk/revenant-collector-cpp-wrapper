#ifndef REVENANTCOLLECTORCPP_DUMPCONFIGDESC_H
#define REVENANTCOLLECTORCPP_DUMPCONFIGDESC_H
#include <string>
#include "RVector.h"
#include "UserDataDesc.h"

namespace Revenant
{
    class DumpConfigDesc
    {
    public:
        DumpConfigDesc(std::string&& dumpDirectory, std::string&& namingPattern, RVector<UserDataDesc>&& userDataDesc);
        ~DumpConfigDesc();

        [[nodiscard]] const std::string& dumpDirectory() const;
        [[nodiscard]] const std::string& namingPattern() const;
        [[nodiscard]] const RVector<UserDataDesc>& userDataDesc() const;

    private:
        struct Impl;
        std::unique_ptr<Impl> _impl;
    };
}

#endif //REVENANTCOLLECTORCPP_DUMPCONFIGDESC_H
