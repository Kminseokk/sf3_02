#ifndef KNIFE_H
#define KNIFE_H

#include "Weapon.h"

class Knife : public Weapon {
public:
    Knife();
    ~Knife();

    void Attack() override;
    void PrintInfo() override; // ���� ���� ��� �޼ҵ� �߰�
};

#endif
