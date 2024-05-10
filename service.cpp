#include "service.h"

void Service::add_service(int number, const string& name, int surface, const string& type) {
	Tentant tentant{ number, name, surface, type };

	validator.validate_tentant(tentant);
	repo.add_repo(tentant);
}

void Service::update_service(int number, const string& name, int surface, const string& type) {
	Tentant tentant{ number, name, surface, type };

	validator.validate_tentant(tentant);
	repo.update_repo(tentant);
}

void Service::delete_service(int number, const string& name) {
	repo.delete_repo(number, name);
}

const Tentant& Service::find_service(int number, const string& name) {
	return repo.get_tentant(number, name);
}



const VectorDinamic<Tentant>& Service::get_all() noexcept {
	return this->repo.get_all();
}

VectorDinamic<Tentant> Service::sort(bool(*cmp_key)(const Tentant&, const Tentant&)) {
	VectorDinamic<Tentant> tentants{ repo.get_all() };
	for (size_t i = 0; i < tentants.get_length() - 1; ++i) {
		for (size_t j = i + 1; j < tentants.get_length(); j++) {
			if (!cmp_key(tentants[i], tentants[j])) {
				Tentant aux = tentants[i];
				tentants[i] = tentants[j];
				tentants[j] = aux;
			}
		}
	}
	return tentants;
}

VectorDinamic<Tentant> Service::filter(const function<bool(const Tentant&)>& fct) {
	VectorDinamic<Tentant> result;
	for (const auto& tentant : repo.get_all()) {
		if (fct(tentant)) {
			result.push_back(tentant);
		}
	}
	return result;
}


VectorDinamic<Tentant> Service::filter_surface(int surface) {
	return filter([surface](const Tentant& tentant) {
		return tentant.get_surface() == surface;
		});
}

VectorDinamic<Tentant> Service::filter_type(const string& type) {
	return filter([type](const Tentant& tentant) {
		return tentant.get_type() == type;
		});
}

VectorDinamic<Tentant> Service::sort_type_surface() {
	return sort(cmp_type_surface);
}

VectorDinamic<Tentant> Service::sort_surface() {
	return sort(cmp_surface);
}

VectorDinamic<Tentant> Service::sort_name() {
	return sort(cmp_name);
}