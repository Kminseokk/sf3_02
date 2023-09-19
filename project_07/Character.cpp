#include "Character.h"
#include <iostream>
using namespace std;

Character::Character() : hp(100), level(1), equippedWeapon(nullptr) {
}

Character::~Character() {
    delete equippedWeapon;
}

void Character::PickUpWeapon(Weapon* weapon) {
    if (equippedWeapon) {
        delete equippedWeapon;
    }
    equippedWeapon = weapon;
}

void Character::AttackWithEquippedWeapon() {
    if (equippedWeapon) {
        equippedWeapon->Attack();
    }
}

int Character::GetHP() const {
    return hp;
}

int Character::GetLevel() const {
    return level;
}

void Character::PrintEquippedWeaponInfo() {
    if (equippedWeapon) {
        std::cout << "현재 장착된 무기 정보: ";
        equippedWeapon->PrintInfo(); // 무기 정보 출력
    }
    else {
        std::cout << "장착된 무기 없음" << std::endl;
    }
}