/* ����
�˸��ٹٶ�� ������ �������Կ��� ������ ��ġ���� �Ѵ�.
�˸��ٹٴ� n���Ը� ���� �� �ִ� ũ���� ������ �ް� �ִ�.
������ ������ ���濡 ���� �� n���Ժ��� Ŀ���� ������ ������ �� ���� ����.
�׸��� ������ �ܴ��ؼ� ������ ũ��� �ɰ� �� ���� ������ 1������ �ִ�.
���� ��� 30kg�� ������ �� �ִ� �����
���� ������ 3������ �ִٰ� ��������.
A���� 5kg, 50��, B���� 10kg, 60��
C���� 20kg, 140���� �� �˸��ٹٰ� ������ �� �ִ� �ִ�������
B�� C������ ������ 200���� �ȴ�.
�츮�� �˸��ٹٰ� ���� ū ������ ������ ���� ����ϴ� ���α׷��� �ۼ��� ���̴�.

ù �ٿ��� ������ ������ �� �ִ� ���Ը�,
���� �ٿ��� ������ ����,
���� �� ���ʹ� �� ������ ���Կ� ���� �� �ٿ� �ϳ��� �Էµȴ�.
������ ũ��� 10000 �����̰�, ������ ������ 100 �� ����
���Կ� ������ 200 ������ �����̴�.


�Է�
30
3
5 50
10 60
20 140

���
30
3
5 50
15 60
20 140

���
190
*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main(void)
{
	int bag = 0;//���� ����
	int jew = 0;//���� ����;
	int* jew_KG; //����
	int* jew_pri; //����
	int i;
	int bag_kg; //���� ���� ����
	int money = 0; //��
	int big_money = 0;//�ִ��̵�

	scanf("%d", &bag);
	scanf("%d", &jew);
	jew_KG = (int*)malloc(sizeof(int) * jew);
	jew_pri = (int*)malloc(sizeof(int) * jew);
	for (i = 0; i < jew; i++)
	{
		scanf("%d %d", &jew_KG[i], &jew_pri[i]);
	}

	for (i = 0; i < jew; i++)
	{
		for (int j = i; j < jew; j++)
		{
			money = 0;
			bag_kg = 0;

			if (jew_KG[j] <= bag)
			{
				bag_kg += jew_KG[j];
				money += jew_pri[j];
			}
			else
			{
				continue;
			}
			if (big_money < money)
			{
				big_money = money;
			}

			for (int k = i + 1; k < jew; k++)
			{
				if (bag_kg + jew_KG[k] <= bag)
				{
					bag_kg += jew_KG[k];
					money += jew_pri[k];
				}
				else
				{
					continue;
				}
				if (big_money < money)
				{
					big_money = money;
				}
				printf("%d %d\n", money, bag_kg);
				bag_kg -= jew_KG[k];
				money -= jew_pri[k];
			}
		}
	}

	printf("%d", big_money);
	free(jew_KG);
	free(jew_pri);
	return 0;
}