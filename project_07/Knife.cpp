#include "Knife.h"
#include <iostream>

Knife::Knife() {
}

Knife::~Knife() {
}

void Knife::Attack() {
    std::cout << "Į�� ���" << std::endl;
}

void Knife::PrintInfo() {
    std::cout << "Į (������: 15, ���� ���� Ƚ��: 3)" << std::endl;
}
