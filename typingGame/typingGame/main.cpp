#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Data.h"
using namespace std;
#define LV 20
#define Init 0
#define Life 3
#define TRUE 1
#define MAX_VALUE 9
#define BONUS_SCORE 3
#define BONUS_LIFE 7
#define LV_1 1
#define LV_2 2
#define LV_3 3
#define LV_4 4
#define LV_5 5

void Initialize(Data* data)
{
	srand((unsigned)time(NULL));
	
	data->lv = TRUE;
	data->Exp = Init;
	data->life = Life;
	data->comp = Init;
	data->bonus = Init;
	data->bExp = Init;
	data->blife = Init;

}


int main()
{
	int i = Init;
	Data data;
	Initialize(&data);
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
		data.bonus = rand() % MAX_VALUE;
		if (data.bonus == BONUS_SCORE)
			data.bExp = TRUE;
		else if (data.bonus == BONUS_LIFE)
			data.blife = TRUE;

		//일반문제 단어 출력 및 입력(레벨 확인)
		if (data.lv == LV_1)
		{
			if (data.bExp == TRUE)
				cout << "BONUS EXP" << endl;
			if (data.blife == TRUE)
				cout << "BONUS LIFE" << endl;


			strcpy(outPut, wordLV1[i]);

			cout << outPut << endl;//출력
			i++;//단어 변수

		}
		else if (data.lv == LV_2)
		{
			if (data.bExp == TRUE)
				cout << "BONUS EXP" << endl;
			if (data.blife == TRUE)
				cout << "BONUS LIFE" << endl;

			strcpy(outPut, wordLV2[i]);
			cout << outPut << endl;//출력
			i++;//단어 변수

		}
		else if (data.lv == LV_3)
		{
			if (data.bExp == TRUE)
				cout << "BONUS EXP" << endl;
			if (data.blife == TRUE)
				cout << "BONUS LIFE" << endl;
			strcpy(outPut, wordLV3[i]);
			cout << outPut << endl;//출력
			i++;//단어 변수
		}

		else if (data.lv == LV_4)
		{
			if (data.bExp == TRUE)
				cout << "BONUS EXP" << endl;
			if (data.blife == TRUE)
				cout << "BONUS LIFE" << endl;
			strcpy(outPut, wordLV4[i]);
			cout << outPut << endl;//출력
			i++;//단어 변수
		}

		else if (data.lv == LV_5)
		{
			if (data.bExp == TRUE)
				cout << "BONUS EXP" << endl;
			if (data.blife == TRUE)
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
			data.Exp++;
			if (data.bExp == 1)
			{
				data.Exp += 2;
				data.bExp = 0;
			}
			else if (data.blife == 1)
			{
				data.life++;
				data.blife = 0;
			}
		}
		else
		{
			system("cls");// 테스트용
			cout << "실패" << endl;// 테스트용
			data.bExp = 0;
			data.blife = 0;
			data.life--;
		}



		//레벨업 가능 판별 후 가능이면 레벨업
		if (data.lv == LV_1 && data.Exp >= 3)
		{
			data.lv++;
			i = 0;

		}

		else if (data.lv == LV_2 && data.Exp >= 6)
		{
			data.lv++;
			i = 0;


		}
		else if (data.lv == LV_3 && data.Exp >= 9)
		{
			data.lv++;
			i = 0;


		}
		else if (data.lv == LV_4 && data.Exp >= 12)
		{
			data.lv++;
			i = 0;


		}
		else if (data.lv == LV_5 && data.Exp >= 15)
		{
			data.lv++;
			i = 0;

		}
		// 승리 여부
		if (data.lv == 6)
		{
			cout << "승리" << endl;
			return 1;
		}

		//라이프 없음 죽음
		if (data.life == 0)
		{
			cout << "패패" << endl;
			exit(1);
		}

		//결과 출력
		cout << "lv" << data.lv << endl;
		cout << "exp" << data.Exp << endl;
		cout << "life" << data.life << endl;
		cout << endl << endl << endl << endl;
		//반복 끝

	}






	return 0;
}