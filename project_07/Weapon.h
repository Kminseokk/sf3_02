#pragma once
#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon(int damage, int attackCount);
    virtual ~Weapon();

    virtual void Attack();
    virtual void PrintInfo() = 0; // 무기 정보 출력 메소드 추가

protected:
    int damage;
    int attackCount;
};

#endif
