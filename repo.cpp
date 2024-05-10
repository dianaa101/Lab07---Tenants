#include "repo.h"
#include <iostream>

int Repo::find_repo(int number, const string& name) {
	for (int i = 0; i < (int)this->tentants.get_length(); i++) {
		if (this->tentants[i].get_number() == number && this->tentants[i].get_name() == name) {
			return i;
		}
	}
	return -1;
}


void Repo::add_repo(const Tentant& tentant) {
	int number = tentant.get_number();
	const string& name = tentant.get_name();

	if (find_repo(number, name) == -1) {
		this->tentants.push_back(tentant);
	}
	else {
		throw RepoException("Tenant already exists!\n");
	}
}

void Repo::update_repo(const Tentant& new_tentant) {

	int number = new_tentant.get_number();
	const string& name = new_tentant.get_name();
	int index = find_repo(number, name);

	if (index != -1) {
		this->tentants[index] = new_tentant;
	}
	else {
		throw RepoException("Tenant doesn't exist!\n");
	}
}

void Repo::delete_repo(int number, const string& name) {
	const int index = find_repo(number, name);
	if (index != -1) {
		this->tentants.erase(index);
	}
	else {
		throw RepoException("Tenant doesn't exist!\n");
	}

}

const Tentant& Repo::get_tentant(int number, const string& name) {
	const int index = find_repo(number, name);

	if (index != -1) {
		return this->tentants[index];
	}
	else {
		throw RepoException("Tenant doesn't exist!\n");
	}
}

const VectorDinamic<Tentant>& Repo::get_all() const noexcept {
	return this->tentants;
}