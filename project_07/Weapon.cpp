#include "Weapon.h"
#include <iostream>

Weapon::Weapon(int damage, int attackCount) : damage(damage), attackCount(attackCount) {
}

Weapon::~Weapon() {
}

void Weapon::Attack() {
    for (int i = 0; i < attackCount; ++i) {
        std::cout << "공격하기" << std::endl;
    }
}
