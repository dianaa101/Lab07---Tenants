#ifndef UI_H_
#define UI_H_

#include "service.h"

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::getline;

class Ui {
    Service& controller;

    void add_ui();
    void update_ui();
    void delete_ui();
    void find_ui();
    void filter_ui();
    void sort_ui();
    static void print_tentants(const VectorDinamic<Tentant>& tentants);
    void print_all();
    void menu();
public:
    explicit Ui(Service& controller) : controller{ controller } {

    }

    //nu lasam sa se faca copie
    Ui(const Ui& copie) = delete;

    void run();

};

void clearInputBuffer();

#endif // UI_H