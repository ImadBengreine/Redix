#include "parser.hpp"
#include <sstream>
#include <algorithm>

Parser::Parser(Store& store) : store(store) {}

std::string Parser::handle(const std::string& input) {
    std::istringstream iss(input);
    std::string cmd, key, value;
    iss >> cmd >> key >> value;

    // uppercase cmd for safety
    for (auto& c : cmd) c = toupper(c);

    if (cmd == "SET") {
        if (key.empty() || value.empty())
            return "ERROR: SET requires key and value";
        store.set(key, value);
        return "OK";
    }
    else if (cmd == "GET") {
        if (key.empty())
            return "ERROR: GET requires a key";
        auto result = store.get(key);
        return result.has_value() ? result.value() : "(nil)";
    }
    else if (cmd == "DEL") {
        if (key.empty())
            return "ERROR: DEL requires a key";
        return store.del(key) ? "OK" : "(nil)";
    }
    else if (cmd == "EXISTS") {
        if (key.empty())
            return "ERROR: EXISTS requires a key";
        return store.exists(key) ? "1" : "0";
    }
    else {
        return "ERROR: unknown command";
    }
}