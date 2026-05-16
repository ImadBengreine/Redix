#pragma once
#include <string>
#include "store.hpp"

class Parser {
private:
	Store& store;

public:
	Parser(Store& store);
	std::string handle(const std::string& input);
};