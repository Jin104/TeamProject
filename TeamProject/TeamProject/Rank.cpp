#include "start.h"

char name[50];
char rankName[50][50];
int rankScore[50];
int nameCount = 0;

//��ŷ����
void ranking(int score)
{
	printf("\t\t\t\tGame Over!\n\n\n");
	printf("\t\t\t�̸��� �Է��ϼ��� :  ");

	gets_s(name);

	printf("\n\t\t\t    %s�� ������ %d\n", name, score);
	nameCount++;

	int i, j, scoreTmp = 0;
	char nameTmp[50];

	for (i = 0; i < 50; i++)			//��ũ�迭 ������������
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

//��ŷ���
void showRanking()
{
	int i;

	drawChar(10, 3, "������ �������� �����÷����ѻ���� ����� �����ϴ�.\n\n\n");
	for (i = 0; i < nameCount; i++)
	{
		printf("\t\t\t\t\t%d�� : %s  %2d��\n", i + 1, rankName[i], rankScore[i]);
	}

}