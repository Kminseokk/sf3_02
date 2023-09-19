#include "Knife.h"
#include <iostream>

Knife::Knife() {
}

Knife::~Knife() {
}

void Knife::Attack() {
    std::cout << "Ä®À» Âî¸£±â" << std::endl;
}

void Knife::PrintInfo() {
    std::cout << "Ä® (µ¥¹ÌÁö: 15, °ø°Ý °¡´É È½¼ö: 3)" << std::endl;
}
