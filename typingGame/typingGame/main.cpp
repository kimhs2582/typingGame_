#include <iostream>
#include <stdlib.h>
#include <string.h>
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



int main()
{
	const char wordLV1[LV][32] =
	{
		"나라","국가","날림","엄마","그림","파리","모기","사과","잔디","즈문","자귀","은솔","안녕","그만","이제","뿜뿜"
	};
	const char wordLV2[LV][32] =
	{
		 "다현","모모","아크","담배","가람","간새","고운","다은","까미","꽃담","아구","대리","감귤"
	};
	const char wordLV3[LV][32] =
	{
		 "엉뚱","어이","끌이","계보","촌수","굳이","마마","미르","물개","물꽃","마녘","연세","나봄","늘봄","지난","사나","사품","손갓","아토","으뜸"
	};
	const char wordLV4[LV][32] =
	{
		 "움찔","해쓱","깨끗","약관","고희","칠순","기쁨","가끔","으뜸","어깨" ,"버그","버드","분석","편집","빠른","속성","참조","고난","힘듦","파일"
	};
	const char wordLV5[LV][32] =
	{
		"딱지","법석","몹시","국립","어학","다솜","닻별","다윈","다흰","든해","잔뜩","훨씬","부썩","살짝","오빠","요새","함수","정리","별찌","뵤뵤"
	};

	char answer[64] = {};
	char outPut[64] = {};

	char input;
	 
	// 초기 설정
	int lv = TRUE;
	int i = Init;
	int Exp = Init;
	int life = Life;
	int comp = Init;
	int bonus = Init;
	int bExp = Init;
	int blife = Init;


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
		bonus = rand() % MAX_VALUE;
		if (bonus == BONUS_SCORE)
			bExp = TRUE;
		else if (bonus == BONUS_LIFE)
			blife = TRUE;

		//일반문제 단어 출력 및 입력(레벨 확인)
		if (lv == LV_1)
		{
			if (bExp == TRUE)
				cout << "BONUS EXP" << endl;
			if (blife == TRUE)
				cout << "BONUS LIFE" << endl;


			strcpy(outPut, wordLV1[i]);

			cout << outPut << endl;//출력
			i++;//단어 변수

		}
		else if (lv == LV_2)
		{
			if (bExp == TRUE)
				cout << "BONUS EXP" << endl;
			if (blife == TRUE)
				cout << "BONUS LIFE" << endl;

			strcpy(outPut, wordLV2[i]);
			cout << outPut << endl;//출력
			i++;//단어 변수

		}
		else if (lv == LV_3)
		{
			if (bExp == TRUE)
				cout << "BONUS EXP" << endl;
			if (blife == TRUE)
				cout << "BONUS LIFE" << endl;
			strcpy(outPut, wordLV3[i]);
			cout << outPut << endl;//출력
			i++;//단어 변수
		}

		else if (lv == LV_4)
		{
			if (bExp == TRUE)
				cout << "BONUS EXP" << endl;
			if (blife == TRUE)
				cout << "BONUS LIFE" << endl;
			strcpy(outPut, wordLV4[i]);
			cout << outPut << endl;//출력
			i++;//단어 변수
		}

		else if (lv == LV_5)
		{
			if (bExp == TRUE)
				cout << "BONUS EXP" << endl;
			if (blife == TRUE)
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
		if (lv == LV_1 && Exp >= 3)
		{
			lv++;
			i = 0;

		}

		else if (lv == LV_2 && Exp >= 6)
		{
			lv++;

		}
		else if (lv == LV_3 && Exp >= 9)
		{
			lv++;

		}
		else if (lv == LV_4 && Exp >= 12)
		{
			lv++;

		}
		else if (lv == LV_5 && Exp >= 15)
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