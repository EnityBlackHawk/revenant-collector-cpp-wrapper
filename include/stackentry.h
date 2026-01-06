#pragma once

#include <string>
#include <memory>


namespace Revenant
{
    class StackEntry
    {
    public:
        StackEntry(std::string&& name, std::string&& file, std::string&& line);
        StackEntry(const StackEntry& other);
        ~StackEntry();
        [[nodiscard]] const std::string& name() const;
        [[nodiscard]] const std::string& file() const;
        [[nodiscard]] const std::string& line() const;
    private:
        struct Impl;
        std::unique_ptr<Impl> _impl;
    };
}

