
#include "Weapon.h"
#include "Gun.h"
#include <iostream>

using namespace std;

Gun::Gun() {
	this->attack_Damage = 10;
	this->attack_Chance = 1;

}


void Gun::Attack() {
	if (attack_Chance > 0) {
		cout << "���� ����- ������ " << attack_Damage << " �� �������ϴ�." << endl;
		this->attack_Chance = attack_Chance - 1;
	}
	else {
		cout << "���� Ƚ���� �����ϴ�." << endl;
	}
}

void Gun::initAttackChance()
{
	this->attack_Chance = 1;
}

void Gun::get_AttackChance()
{
	cout << "�ش� ����(��)�� ���� ���� Ƚ���� " << attack_Chance << "�� �Դϴ�." << endl;
}

int Gun::get_AttackDamage()
{
	return attack_Damage;
}

int Gun::check_AttackChance()
{
	return attack_Chance;
}
