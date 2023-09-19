////////////////////////////////////////////////////////////////////////////
//      :: C++ 프로젝트 07 번 문제 ::
//      1. 캐릭터, 무기, 칼, 총 클래스를 만들어준다.
//      2. 캐릭터 클래스
//          -필드: ‘hp’, ‘level’, ‘무기들’
//          - 메소드 : 무기 줍기, 공격하기(공격하기 메소드에서는 가지고 있는 무기들만 사용해서 
//            공격할 수 있으며, 공격당한 캐릭터의 hp가 해당하는 무기의 공격력만큼 감소한다.)
//      3. 무기 클래스
//          - 필드: 공격력, 공격 가능 횟수
//          - 메소드 : 공격하기
//      4. 총 & 칼 클래스(무기 클래스를 상속 받는 클래스)
//          - 칼 : 공격력 - 5, 공격가능횟수 - 3, 공격하기 - "찌르기" 출력
//          - 총 : 공격력 - 10, 공격가능횟수 - 1, 공격하기 - "총쏘기" 출력
//      5. 파일 분리하기.
// 
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Character.h"
#include "Gun.h"
#include "Knife.h"

using namespace std;

int main() {
    // Character 객체 생성
    Character character;

    // Gun 객체 생성
    Gun* gun = new Gun();

    // Knife 객체 생성
    Knife* knife = new Knife();

    int user_choice;

    cout << "★★★★★★★★★★★★★★★★★★★" << endl;
    cout << "★ 1. 유저 정보 출력 " << endl;
    cout << "★ 2. 유저 총기 획득 " << endl;
    cout << "★ 3. 유저 소드 획득 " << endl;
    cout << "★ 4. 공격 하기 !!!! " << endl;
    cout << "★ 5. 종료 해주 세요 " << endl;
    cout << "★★★★★★★★★★★★★★★★★★★" << endl;
    cout << "\n\n";

    while (1) {
        cout << " ▶ 무엇을 할까? : ";
        cin >> user_choice;

        if (user_choice == 1) { // 1. 유저 정보 출력
            cout << "캐릭터의 HP: " << character.GetHP() << "입니다." << endl;
            cout << "캐릭터의 Level: " << character.GetLevel() << "입니다."<< endl;
            cout << "캐릭터가 가진 무기 " << character.PrintEquippedWeaponInfo() << "입니다." << endl;
            cout << "\n";
        }
        if (user_choice == 2) { // 2. 유저 총기 획득
            character.PickUpWeapon(gun);
            cout << "캐릭터가 총을 획득해서 소지했습니다." << endl;
            cout << "\n";
        }
        if (user_choice == 3) { // 3. 유저 소드 획득
            character.PickUpWeapon(knife);
            cout << "캐릭터가 칼을 획득해서 소지했습니다." << endl;
            cout << "\n";
        }
        if (user_choice == 4) { // 4. 공격 하기 !!!!

        }
        if (user_choice == 5) { // 5. 종료

        }



    }
    // 캐릭터가 공격하기
    std::cout << "캐릭터의 HP: " << character.GetHP() << std::endl;
    //character.Attack();


    return 0;
}
