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

	for (i = 0; i < 50; i++)			//랭크배열 내림차순정렬
	{									
		if (rankScore[i] <= score)	   		
		{
			scoreTmp = rankScore[i];		
			for (j = 0; j < 50; j++)
			{
				nameTmp[j] = rankName[i][j]; 
			}
			rankScore[i] = score;		
			for (j = 0; j < 50; j++)
			{
				rankName[i][j] = name[j];
			}
			score = scoreTmp;			
			for (j = 0; j < 50; j++)
			{
				name[j] = nameTmp[j];	
			}
		}
	}
}

//랭킹출력
void showRanking()
{
	int i;

	drawChar(10, 3, "점수가 같을경우는 먼저플레이한사람이 등수가 높습니다.\n\n\n");
	for (i = 0; i < nameCount; i++)
	{
		printf("\t\t\t\t\t%d등 : %s  %2d점\n", i + 1, rankName[i], rankScore[i]);
	}

}