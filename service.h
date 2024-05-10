#ifndef SERVICE_H_
#define SERVICE_H_

#include "repo.h" 
#include "validator.h" 

#include <string>
#include <vector>
#include <functional>

using std::string;
using std::vector;
using std::function;


class Service {
    Repo& repo;
    Validator& validator;
    /*
    * Sorts the object list
    * Compares 2 objects
    * Gets a key used for sorting
    * Returns: a copy of the sorted list
    */
    VectorDinamic<Tentant> sort(bool(*cmp_key)(const Tentant&, const Tentant&));

    /*
    * Filters the object list
    * Gets as parameter a function
    * Returns: the filtered objects
    */
    VectorDinamic<Tentant> filter(const function<bool(const Tentant&)>& fct);



public:
    Service(Repo& repo, Validator& validator) : repo{ repo }, validator{ validator } {

    }

    //nu putem lasa sa se faca copie
    Service(const Service& copy) = delete;

    /*
    * Add a tenant
    * Throws exception if it already exists or if validation fails
    */
    void add_service(int number, const string& name, int surface, const string& type);
    void update_service(int number, const string& name, int surface, const string& type);

    /*
    * Deletes a tenant
    * Throws exception if the tenant doesn't exist
    */
    void delete_service(int number, const string& name);

    /*
    * Finds a tenant by a number and name
    * Throws exception if tenant doesn't exist
    */
    const Tentant& find_service(int number, const string& name);
    const VectorDinamic<Tentant>& get_all() noexcept;

    /*
    * Filters by surface
    */

    VectorDinamic<Tentant> filter_surface(int surface);
    /*
    * Filters by type
    */
    VectorDinamic<Tentant> filter_type(const string& type);

    /*
    * Sorts by type + surface
    */
    VectorDinamic<Tentant> sort_type_surface();

    /*
    * Sorts by surface
    */
    VectorDinamic<Tentant> sort_surface();

    /*
    * Sorts by the name of the owner
    */
    VectorDinamic<Tentant> sort_name();
};

#endif // SERVICE_H