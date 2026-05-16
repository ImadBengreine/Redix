#include "store.hpp"

void Store::set(const std::string& key, const std::string& value) {
    if (key.empty() || value.empty())
        return;
    data[key] = value;
}

std::optional<std::string> Store::get(const std::string& key) {
    if (data.contains(key))
        return data[key];
    return std::nullopt;
}

bool Store::del(const std::string& key) {
    return data.erase(key) > 0;
}

bool Store::exists(const std::string& key) {
    return data.contains(key);
}