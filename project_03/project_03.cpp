////////////////////////////////////////////////////////////////////////////
//      :: C++ 프로젝트 03 번 문제 ::
//      1)   컴퓨터가 1~25까지의 수 중 랜덤으로 6개의 수 지정(중복 x)
//      2)   사용자도 1~25까지의 수 중 원하는 숫자 6개 입력(중복 x)
//      3)   두 배열을 비교해서 몇 등인지 출력하기!
//      3-1) 한 개도 맞추지 못하면 7등, 1개만 맞추면 6등, 2개 맞추면 5등...
//      3-2) 6개를 모두 맞추면 1등
//
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include <vector>

using namespace std;

int main()
{
    srand(time(NULL));

	int Computer_num[6]; //컴퓨터가 생성한 번호
	int check[46] = { 0, }; //벡터에 랜덤한 값을 넣기위해
	int num;
	vector<int> User_number; //유저가 만드는 번호


	for (int i = 0; i < 6; i++) {
		do {
			num = std::rand() % 45 + 1;
		} while (check[num] == 1);
		Computer_num[i] = num;
		check[num] = 1;
	} //랜덤한 중복 제외의 6개의 숫자 생성

	
	while (User_number.size() < 6 ){
		int num;
		bool isDuplicate = false;

		// 사용자로부터 숫자 입력 받기
		cout << "숫자를 입력하세요: ";
		cin >> num;
		cout << "\n";

		// 중복 확인
		if (find(User_number.begin(), User_number.end(), num) != User_number.end()) {
			cout << "이미 입력한 숫자입니다. 다시 입력하세요." << endl;
			isDuplicate = true;
		}

		// 중복된 숫자가 아닌 경우에만 벡터에 추가
		if (!isDuplicate) {
			User_number.push_back(num);
		}
	}

	// 같은 숫자 개수 세기
	int count = 0;
	for (int i = 0; i < 6; i++) {
		if (find(User_number.begin(), User_number.end(), Computer_num[i]) != User_number.end()) {
			count++;
		}
	}	//User_number.end()의 값이 반환되면 컴퓨터숫자와 일치하는게 없다는 의미. (인덱스 값 반환)
		//반대로 생각하면, 반환된 값이 User_number.end() 이랑 다르다면, 같은 값을 찾았단 의미이다.
			


	cout << "\n사용자의 입력 번호 !" << endl;
	for (auto n : User_number) {
		cout << n << " ";
	}
	cout << "\n";

	cout << "\n당첨 번호 공개 !" << endl;
	for (auto n : Computer_num) {
		cout <<  n << " ";
	}
	cout << "\n";
	cout << "***********************************************";
	cout << "\n1 ~ 7등 까지의 결과가 나올 수 있습니다. " << endl;

	// 같은 숫자 개수에 따른 등수 출력
	if (count == 6) {
		cout << "1등! 6개의 모든 숫자를 맞추셨습니다." << endl;
	}
	else if (count == 5) {
		cout << "2등! 5개의 숫자를 맞추셨습니다." << endl;
	}
	else if (count == 4) {
		cout << "3등! 4개의 숫자를 맞추셨습니다." << endl;
	}
	else if (count == 3) {
		cout << "4등! 3개의 숫자를 맞추셨습니다." << endl;
	}
	else if (count == 2) {
		cout << "5등! 2개의 숫자를 맞추셨습니다." << endl;
	}
	else if (count == 1) {
		cout << "6등! 1개의 숫자를 맞추셨습니다." << endl;
	}
	else {
		cout << "7등! 당첨 숫자가 없습니다." << endl;
	}





}

