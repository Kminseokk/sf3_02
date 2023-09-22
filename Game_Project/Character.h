#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include "Weapon.h"
#include <iostream>
//- �ʵ�: ��hp��, ��level��, ������顯
//- �޼ҵ� : ���� �ݱ�, �����ϱ�(�����ϱ� �޼ҵ忡���� ������ �ִ� ����鸸 ����ؼ� ��
//    ���� �� ������, ���ݴ��� ĳ������ hp�� �ش��ϴ� ������ ���ݷ¸�ŭ �����Ѵ�.
using namespace std;

class Character {
private:
    string name;
    int hp;
    int level;
    vector<int> weapons;

public:
    Character(string name);
    virtual ~Character() {}

    void Player_Attack();
    void Player_GetWeapon(int WeaponIndex);
    int get_hp();
    int get_level();
    string get_name();
    void get_weapon();
    int get_weaponIndex();
    void set_hp(int hp); // ���ݹް� �� ���ΰ� ����
};

#endif
