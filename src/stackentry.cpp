
#include "stackentry.h"
namespace Revenant
{
    struct StackEntry::Impl {
        std::string name;
        std::string file;
        std::string line;
    };

    StackEntry::StackEntry(std::string&& name, std::string&& file, std::string&& line) :
    _impl(std::make_unique<Impl>())
    {
        _impl->name = name;
        _impl->file = file;
        _impl->line = line;
    }

    StackEntry::StackEntry(const StackEntry& other) : _impl(std::make_unique<Impl>())
    {
        _impl->name = other._impl->name;
        _impl->file = other._impl->file;
        _impl->line = other._impl->line;
    }

    StackEntry::~StackEntry() = default;

    const std::string& StackEntry::name() const
    {
        return _impl->name;
    }

    const std::string& StackEntry::file() const
    {
        return _impl->file;
    }

    const std::string& StackEntry::line() const
    {
        return _impl->line;
    }
}