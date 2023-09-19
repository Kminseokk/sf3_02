#include "Weapon.h"
#include <vector> // vector 헤더 파일 포함

#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character {
public:
    Character();  // 생성자
    ~Character(); // 소멸자

    void PickUpWeapon(Weapon* weapon); //무기 획득 메소드
    void AttackWithEquippedWeapon(); // 현재 장착된 무기로 공격하기 메소드

    int GetHP() const;
    int GetLevel() const;

    void PrintEquippedWeaponInfo(); // 장착된 무기 정보 출력 메소드 추가

private:
    int hp;
    int level;
    int equippedWeaponIndex; // 현재 장착된 무기의 인덱스
    Weapon* equippedWeapon;

};

#endif
