#ifndef GUN_H
#define GUN_H

#include "Weapon.h"

class Gun : public Weapon {
public:
    Gun();
    ~Gun();

    void Attack() override;
    void PrintInfo() override; // ���� ���� ��� �޼ҵ� �߰�
};

#endif
