#include "validator.h"

void Validator::validate_number(int number)
{
	if (number <= 0) {
		throw ValidatorException("Invalid number! \n");
	}
}

void Validator::validate_name(const string& name) {
	if (name.empty()) {
		throw ValidatorException("Invalid name! \n");
	}
}

void Validator::validate_surface(int surface) {
	if (surface <= 0) {
		throw ValidatorException("Invalid surface! \n");
	}
}

void Validator::validate_type(const string& type) {
	if (type.empty()) {
		throw ValidatorException("Invalid type! \n");
	}
}

void Validator::validate_tentant(const Tentant& tentant) {
	int number = tentant.get_number();
	const string& name = tentant.get_name();
	int surface = tentant.get_surface();
	const string& type = tentant.get_type();
	string exceptions;

	try {
		validate_number(number);
	}
	catch (ValidatorException& mesaj) {
		exceptions += mesaj.get_mesaj();
	}

	try {
		validate_name(name);
	}
	catch (ValidatorException& mesaj) {
		exceptions += mesaj.get_mesaj();
	}

	try {
		validate_surface(surface);
	}
	catch (ValidatorException& mesaj) {
		exceptions += mesaj.get_mesaj();
	}

	try {
		validate_type(type);
	}
	catch (ValidatorException& mesaj) {
		exceptions += mesaj.get_mesaj();
	}

	if (!exceptions.empty()) {
		throw ValidatorException(exceptions);
	}
}