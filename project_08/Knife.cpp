
#include "Weapon.h"
#include "Knife.h"
#include <iostream>

using namespace std;

Knife::Knife() {
	this->attack_Damage = 5;
	this->attack_Chance = 3;

}

void Knife::initAttackChance()
{
	this->attack_Chance = 3;
}

void Knife::get_AttackChance() {
	cout << "�ش� ����(Į)�� ���� ���� Ƚ���� " << attack_Chance << "�� �Դϴ�." << endl;
}

int Knife::get_AttackDamage()
{
	return attack_Damage;
}

int Knife::check_AttackChance()
{
	return attack_Chance;
}

void Knife::Attack() {
	if (attack_Chance > 0) {
		cout << "���� �ξ�- ������ " << attack_Damage << " �� �������ϴ�." << endl;
		this->attack_Chance = attack_Chance - 1;
	}
	else {
		cout << "���� Ƚ���� �����ϴ�." << endl;
	}
}
