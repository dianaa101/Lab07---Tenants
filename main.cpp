#include "domain.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include "tests.h"

#include <iostream>
using namespace std;

void create() {
	Tests tests;
	tests.test_all();

	VectorDinamic<Tentant> vector;
	Repo repo(vector);
	Validator validator;
	Service controller(repo, validator);
	Ui ui{ controller };

	ui.run();
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	create();
	_CrtDumpMemoryLeaks();
	cout << "No Memory Leaks \n";
}