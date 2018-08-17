#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Data.h"
#include "wordLV.h"
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
void GenerateBonus(Data* data)
{
	data->bonus = rand() % MAX_VALUE;
	if (data->bonus == BONUS_SCORE)
		data->bExp = TRUE;
	else if (data->bonus == BONUS_LIFE)
		data->blife = TRUE;
}
void InitScreen()
{
	char input;
	cout << "typingGame" << endl;
	cout << endl;
	cout << endl;

	cout << "시작할려면 아무키 + 엔터" << endl;
	cin >> input;
	system("cls");
	cout << "시작 !" << endl;
}

void GenerateAnswer(Data*data, WordLV* wordLV)
{
	if (data->lv == LV_1)
	{
		if (data->bExp == TRUE)
			cout << "BONUS EXP" << endl;
		if (data->blife == TRUE)
			cout << "BONUS LIFE" << endl;


		strcpy(data->outPut, wordLV->wordLV1[data->i]);

		cout << data->outPut << endl;//출력
		data->i++;//단어 변수

	}
	else if (data->lv == LV_2)
	{
		if (data->bExp == TRUE)
			cout << "BONUS EXP" << endl;
		if (data->blife == TRUE)
			cout << "BONUS LIFE" << endl;

		strcpy(data->outPut, wordLV->wordLV2[data->i]);
		cout << data->outPut << endl;//출력
		data->i++;//단어 변수

	}
	else if (data->lv == LV_3)
	{
		if (data->bExp == TRUE)
			cout << "BONUS EXP" << endl;
		if (data->blife == TRUE)
			cout << "BONUS LIFE" << endl;
		strcpy(data->outPut, wordLV->wordLV3[data->i]);
		cout << data->outPut << endl;//출력
		data->i++;//단어 변수
	}

	else if (data->lv == LV_4)
	{
		if (data->bExp == TRUE)
			cout << "BONUS EXP" << endl;
		if (data->blife == TRUE)
			cout << "BONUS LIFE" << endl;
		strcpy(data->outPut, wordLV->wordLV4[data->i]);
		cout << data->outPut << endl;//출력
		data->i++;//단어 변수
	}

	else if (data->lv == LV_5)
	{
		if (data->bExp == TRUE)
			cout << "BONUS EXP" << endl;
		if (data->blife == TRUE)
			cout << "BONUS LIFE" << endl;
		strcpy(data->outPut, wordLV->wordLV4[data->i]);
		cout << data->outPut << endl;//출력
		data->i++;//단어 변수
	}
}

int main()
{
	int i = Init;
	Data data;
	WordLV wordLV;
	Initialize(&data);
	

	

	

	// 초기 설정
	
	InitScreen();

	// 초기 화면
	
	//반복
	while (1)
	{
		//보너스 생성 
		GenerateBonus(&data);

		//일반문제 단어 출력 및 입력(레벨 확인)
		GenerateAnswer(&data, &wordLV);
		//정답 입력
		cin >> data.answer;

		//정답 여부 판별후 정산
		if (strcmp(data.outPut, data.answer) == 0)
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
			data.i = 0;

		}

		else if (data.lv == LV_2 && data.Exp >= 6)
		{
			data.lv++;
			data.i = 0;


		}
		else if (data.lv == LV_3 && data.Exp >= 9)
		{
			data.lv++;
			data.i = 0;


		}
		else if (data.lv == LV_4 && data.Exp >= 12)
		{
			data.lv++;
			data.i = 0;


		}
		else if (data.lv == LV_5 && data.Exp >= 15)
		{
			data.lv++;
			data.i = 0;

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