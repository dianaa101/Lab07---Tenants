#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "exceptions.h"
#include "domain.h"

using std::string;

class Validator {
private:
	static void validate_number(int number);
	static void validate_name(const string& name);
	static void validate_surface(int surface);
	static void validate_type(const string& type);
public:
	static void validate_tentant(const Tentant& tentant);
};

#endif 