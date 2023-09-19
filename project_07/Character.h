#include "Weapon.h"
#include <vector> // vector ��� ���� ����

#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character {
public:
    Character();  // ������
    ~Character(); // �Ҹ���

    void PickUpWeapon(Weapon* weapon); //���� ȹ�� �޼ҵ�
    void AttackWithEquippedWeapon(); // ���� ������ ����� �����ϱ� �޼ҵ�

    int GetHP() const;
    int GetLevel() const;

    void PrintEquippedWeaponInfo(); // ������ ���� ���� ��� �޼ҵ� �߰�

private:
    int hp;
    int level;
    int equippedWeaponIndex; // ���� ������ ������ �ε���
    Weapon* equippedWeapon;

};

#endif
