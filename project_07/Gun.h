#ifndef GUN_H
#define GUN_H

#include "Weapon.h"

class Gun : public Weapon {
public:
    Gun();
    ~Gun();

    void Attack() override;
    void PrintInfo() override; // 무기 정보 출력 메소드 추가
};

#endif
