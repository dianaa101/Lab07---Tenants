#include "domain.h"

#include <iostream>
using namespace std;

Tentant::Tentant() {
	this->number = 0;
	this->name = "";
	this->surface = 0;
	this->type = "";
}

// constructor
Tentant::Tentant(int number, const string& name, int surface, const string& type) {
	this->number = number;
	this->name = name;
	this->surface = surface;
	this->type = type;
}

// destructor
Tentant::~Tentant() = default;

// copie constructor
Tentant::Tentant(const Tentant& tentant) {
	this->number = tentant.number;
	this->name = tentant.name;
	this->surface = tentant.surface;
	this->type = tentant.type;
}

// getters

int Tentant::get_number() const noexcept {
	return this->number;
}

const string& Tentant::get_name() const noexcept {
	return this->name;
}

int Tentant::get_surface() const noexcept {
	return this->surface;
}

const string& Tentant::get_type() const noexcept {
	return this->type;
}

// setters

void Tentant::set_name(const string& new_name) {
	this->name = new_name;
}

/// TO STRING PRINTARE
string Tentant::to_string_print() {
	return "\t\033[1;33mNumber: \033[0m" + to_string(this->number) + ";   \033[1;33mName: \033[0m" + this->name +
		";   \033[1;33mSurface: \033[0m" + to_string(this->surface) + ";   \033[1;33mType: \033[0m" + this->type + ".";
}

// operators
Tentant& Tentant::operator=(const Tentant& copy) = default;

bool Tentant::operator==(const Tentant& copy) {
	return this->number == copy.number && this->name == copy.name;
}


// comparing functions
bool cmp_number(const Tentant& t1, const Tentant& t2) {
	if (t1.get_number() < t2.get_number()) {
		return true;
	}
	return false;
}

bool cmp_name(const Tentant& t1, const Tentant& t2) {
	if (t1.get_name() < t2.get_name()) {
		return true;
	}
	return false;
}

bool cmp_surface(const Tentant& t1, const Tentant& t2) {
	if (t1.get_surface() < t2.get_surface()) {
		return true;
	}
	return false;
}

bool cmp_type(const Tentant& t1, const Tentant& t2) {
	if (t1.get_type() != t2.get_type()) {
		return t1.get_type() < t2.get_type();
	}
	return t1.get_number() < t2.get_number(); // To ensure a stable sort
}

bool cmp_type_surface(const Tentant& t1, const Tentant& t2) {
	if (t1.get_type() != t2.get_type()) {
		return t1.get_type() < t2.get_type(); 
	}
	else {
		return t1.get_surface() < t2.get_surface(); 
	}
}