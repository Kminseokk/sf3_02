#include "Gun.h"
#include <iostream>

Gun::Gun() {
}

Gun::~Gun() {
}

void Gun::Attack() {
    std::cout << "»§¾ß" << std::endl;
}

void Gun::PrintInfo() {
    std::cout << "ÃÑ (µ¥¹ÌÁö: 10, °ø°İ °¡´É È½¼ö: 5)" << std::endl;
}
