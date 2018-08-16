#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define LV 20



int main()
{


	const char wordLV1[LV][32] =
	{
		"나라","국가","날림","엄마","그림","파리","모기","사과"
	};
	const char wordLV2[LV][32] =
	{
		"나달","날두","아크","담배","아구","대리","감귤"
	};
	const char wordLV3[LV][32] =
	{
		"가가","나나","다다","라라","마마","바바","사사"
	};
	const char wordLV4[LV][32] =
	{
		"갸갸","거거","겨겨","고고","교교","구구","규규"
	};
	const char wordLV5[LV][32] =
	{
		"나다","다라","마바","바사","사아","아자"
	};

	char answer[64] = {};
	char outPut[64] = {};

	char input;

	// 초기 설정
	int lv = 1;
	int i = 0;
	int Exp = 0;
	int life = 3;
	int comp = 0;
	int bonus = 0;
	int bExp = 0;
	int blife = 0;


	// 초기 화면
	cout << "typingGame" << endl;
	cout << endl;
	cout << endl;

	cout << "시작할려면 아무키 + 엔터" << endl;
	cin >> input;
	system("cls");
	cout << "시작 !" << endl;
	//반복
	while (1)
	{
		//보너스 생성 
		bonus = rand() % 9;
		if (bonus == 3)
			bExp = 1;
		else if (bonus == 7)
			blife = 1;

		//일반문제 단어 출력 및 입력(레벨 확인)
		if (lv == 1)
		{
			if (bExp == 1)
				cout << "BONUS EXP" << endl;
			if (blife == 1)
				cout << "BONUS LIFE" << endl;


			strcpy(outPut, wordLV1[i]);

			cout << outPut << endl;//출력
			i++;//단어 변수

		}
		else if (lv == 2)
		{
			if (bExp == 1)
				cout << "BONUS EXP" << endl;
			if (blife == 1)
				cout << "BONUS LIFE" << endl;

			strcpy(outPut, wordLV2[i]);
			cout << outPut << endl;//출력
			i++;//단어 변수

		}
		else if (lv == 3)
		{
			if (bExp == 1)
				cout << "BONUS EXP" << endl;
			if (blife == 1)
				cout << "BONUS LIFE" << endl;
			strcpy(outPut, wordLV3[i]);
			cout << outPut << endl;//출력
			i++;//단어 변수
		}

		else if (lv == 4)
		{
			if (bExp == 1)
				cout << "BONUS EXP" << endl;
			if (blife == 1)
				cout << "BONUS LIFE" << endl;
			strcpy(outPut, wordLV4[i]);
			cout << outPut << endl;//출력
			i++;//단어 변수
		}

		else if (lv == 5)
		{
			if (bExp == 1)
				cout << "BONUS EXP" << endl;
			if (blife == 1)
				cout << "BONUS LIFE" << endl;
			strcpy(outPut, wordLV4[i]);
			cout << outPut << endl;//출력
			i++;//단어 변수
		}
		//정답 입력
		cin >> answer;

		//정답 여부 판별후 정산
		if (strcmp(outPut, answer) == 0)
		{
			system("cls");// 테스트용
			cout << "성공" << endl;// 테스트용
			Exp++;
			if (bExp == 1)
			{
				Exp += 2;
				bExp = 0;
			}
			else if (blife == 1)
			{
				life++;
				blife = 0;
			}
		}
		else
		{
			system("cls");// 테스트용
			cout << "실패" << endl;// 테스트용
			bExp = 0;
			blife = 0;
			life--;
		}



		//레벨업 가능 판별 후 가능이면 레벨업
		if (lv == 1 && Exp >= 3)
		{
			lv++;
			i = 0;

		}

		else if (lv == 2 && Exp >= 6)
		{
			lv++;

		}
		else if (lv == 3 && Exp >= 9)
		{
			lv++;

		}
		else if (lv == 4 && Exp >= 12)
		{
			lv++;

		}
		else if (lv == 5 && Exp >= 15)
		{
			lv++;
		}
		// 승리 여부
		if (lv == 6)
		{
			cout << "승리" << endl;
			return 1;
		}

		//라이프 없음 죽음
		if (life == 0)
		{
			cout << "패패" << endl;
			exit(1);
		}

		//결과 출력
		cout << "lv" << lv << endl;
		cout << "exp" << Exp << endl;
		cout << "life" << life << endl;
		cout << endl << endl << endl << endl;
		//반복 끝

	}






	return 0;
}