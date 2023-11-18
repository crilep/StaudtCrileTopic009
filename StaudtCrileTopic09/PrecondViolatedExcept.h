#pragma once

#include<stdexcept>
#include<string>

class PrecondViolatedExcept : public std::logic_error {
public:
	PrecondViolatedExcept(const std::string& message = "");
};