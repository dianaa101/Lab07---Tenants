#ifndef DOMAIN_H_
#define DOMAIN_H_

#include <string>
using std::string;

class Tentant {

private:
	int number;
	string name;
	int surface;
	string type;

public:
	/*
	* the constructor of the tentant
	*
	* A tentant has:
	*	~number
	*	~name
	*	~surface
	*	~type
	*/

	Tentant(int number, const string& name, int surface, const string& type);

	/*
	* Default constructor
	*/

	Tentant();

	/*
	* Destructor
	*/

	~Tentant();

	/*
	* Constructor copy
	*/
	Tentant(const Tentant& tentant);

	// getters
	/*
	* Get the number of tenant's apartment
	*/
	[[nodiscard]] int get_number() const noexcept;

	/*
	* Get the name of the tenant
	*/
	[[nodiscard]] const string& get_name() const noexcept;

	/*
	* Get the surface of the apartment
	*/

	[[nodiscard]] int get_surface() const noexcept;

	/*
	* Get the type
	*/

	[[nodiscard]] const string& get_type() const noexcept;

	// setters

	[[maybe_unused]] void set_name(const string& new_name);

	/*
	* Print function
	*/
	string to_string_print();

	// Operator used to assign a copy
	Tentant& operator=(const Tentant& copy);

	// Equality operator between two objects 
	bool operator==(const Tentant& copy);

};
// comparatori

// returns TRUE if t1.get_number() < t2.get_number()
bool cmp_number(const Tentant& t1, const Tentant& t2);

// returns TRUE if t1.get_name() < t2.get_name()
bool cmp_name(const Tentant& t1, const Tentant& t2);

// returns TRUE if t1.get_surface() < t2.get_surface()
bool cmp_surface(const Tentant& t1, const Tentant& t2);

// returs TRUE if t1.get_type() < t2.get_type()
bool cmp_type(const Tentant& t1, const Tentant& t2);

bool cmp_type_surface(const Tentant& t1, const Tentant& t2);


#endif
