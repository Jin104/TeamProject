#include "start.h"

char name[50];
char rankName[50][50];
int rankScore[50];
int nameCount = 0;

//랭킹저장
void ranking(int score)
{
	printf("\t\t\t\tGame Over!\n\n\n");
	printf("\t\t\t이름을 입력하세요 :  ");

	gets_s(name);

	printf("\n\t\t\t    %s의 점수는 %d\n", name, score);
	nameCount++;

	int i, j, scoreTmp = 0;
	char nameTmp[50];

	for (i = 0; i < 50; i++)				//랭크배열 돌아가면서
	{										//낮은 점수 찾으면 내림차순정렬
		if (rankScore[i] <= score)	   		 //만약 랭크점수가 새로운 점수보다 낮으면
		{
			scoreTmp = rankScore[i];		 //임시점수변수에 랭크점수넣기
			for (j = 0; j < 50; j++)
			{
				nameTmp[j] = rankName[i][j]; //임시이름변수에 랭크이름넣기(점수낮은)
			}
			rankScore[i] = score;			 //랭킹점수는 새로운 점수
			for (j = 0; j < 50; j++)
			{
				rankName[i][j] = name[j];	 //랭킹이름은 새로운 이름
			}
			score = scoreTmp;				 //점수는 임시점수변수에 넣은값
			for (j = 0; j < 50; j++)
			{
				name[j] = nameTmp[j];		 //이름은 임시이름변수에 넣은값
			}
		}
	}


}

//랭킹출력
void showRanking()
{
	int i;
	//system("cls");
	drawChar(10, 3, "점수가 같을경우는 먼저플레이한사람이 등수가 높습니다.\n\n\n");
	for (i = 0; i < nameCount; i++)
	{
		printf("\t\t\t\t\t%d등 : %s  %2d점\n", i + 1, rankName[i], rankScore[i]);
	}

}