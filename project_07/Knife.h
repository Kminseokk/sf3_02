#pragma once // �ѹ� �о�� �߰�     
#include "Weapon.h"
#ifndef KNIFE_H
#define KNIFE_H
using std::string;


class Knife : public Weapon {

public:
	Knife();
	void Attack();

	void initAttackChance(); //���ο� ���⸦ ȹ������ �� ���� ����Ƚ�� �ʱ�ȭ.
	void get_AttackChance(); // ����Ƚ���� ��Ÿ���� ����.
	int get_AttackDamage(); //������ 
	int check_AttackChance(); //����Ƚ�� üũ
};


#endif
