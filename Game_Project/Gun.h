#pragma once // �ѹ� �о�� �߰������� ���� �ʵ����ϴ� ���. ǥ���� �ƴϹǷ� �۵����� ���� �� �ִ�.
#include <iostream>
#include "Weapon.h"
#ifndef GUN_H
#define GUN_H
using std::string;


class Gun : public Weapon {

public:
	Gun();
	void Attack();

	void initAttackChance(); //���ο� ���⸦ ȹ������ �� ���� ����Ƚ�� �ʱ�ȭ.
	void get_AttackChance();
	int get_AttackDamage(); //������ 
	int check_AttackChance(); //����Ƚ�� üũ
};


#endif
