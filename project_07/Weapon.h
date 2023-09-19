#pragma once
#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon(int damage, int attackCount);
    virtual ~Weapon();

    virtual void Attack();
    virtual void PrintInfo() = 0; // ���� ���� ��� �޼ҵ� �߰�

protected:
    int damage;
    int attackCount;
};

#endif
