#pragma once
#include <iostream>
using std::string;

#ifndef __WEAPON_H__ // __PERSON_H__�� define ���� �ʾҴٸ�,
#define __WEAPON_H__ // #endif�� ������ ������ ���Խ��Ѷ� 

//- �ʵ�: ���ݷ�, ���� ���� Ƚ��
//- �޼ҵ�: �����ϱ�


class Weapon {
protected:
    int attack_Damage; //���ݷ�
    int attack_Chance; //���� ���� Ƚ��

public:
    Weapon();
    virtual ~Weapon() {}

    virtual void Attack() = 0;
};

#endif
