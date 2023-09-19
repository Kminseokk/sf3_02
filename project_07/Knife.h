#ifndef KNIFE_H
#define KNIFE_H

#include "Weapon.h"

class Knife : public Weapon {
public:
    Knife();
    ~Knife();

    void Attack() override;
    void PrintInfo() override; // 무기 정보 출력 메소드 추가
};

#endif
