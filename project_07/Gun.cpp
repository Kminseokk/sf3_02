#include "Gun.h"
#include <iostream>

Gun::Gun() {
}

Gun::~Gun() {
}

void Gun::Attack() {
    std::cout << "����" << std::endl;
}

void Gun::PrintInfo() {
    std::cout << "�� (������: 10, ���� ���� Ƚ��: 5)" << std::endl;
}
