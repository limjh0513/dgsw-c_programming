#include <stdio.h>
#pragma warning(disable : 4996)

int main(void)
{
	int n;
	int i;
	int fbo1 = 1; //�Ǻ���ġ�� ù��°�� 1
	int fbo2 = 1; //�Ǻ���ġ�� �ι�°�� 1
	int fbo3 = 1; //for���� 3���� ���۵Ǵµ� 1,2�� �ԷµǸ� ����� 1�� �Ǿ���

	scanf("%d", &n); //�Է�

	for (i = 3; i <= n; i++) //3���� ����
	{
		fbo3 = fbo1 + fbo2; //fbo3�� fbo1+fbo2

		fbo1 = fbo2; //fbo1�� fbo2 ���� �־���
		fbo2 = fbo3; //fbo2�� fbo3 ���� �־���
	}

	printf("%d", fbo3); //fbo3 -> �Ǻ���ġ n��° �� ���

	return 0;
}

//int main(void) ���� ���� �ڵ�
//{
//	int n;
//	int i;
//	int fbo1 = 1; //�Ǻ���ġ�� ù��°�� 1
//	int fbo2 = 1; //�Ǻ���ġ�� �ι�°�� 1
//	int fbo3 = 1; //for���� 3���� ���۵Ǵµ� 1,2�� �ԷµǸ� ����� 1�� �Ǿ���
//	int step = 0; //�Ǻ���ġ ���� ���� �� ������� ����
//
//	scanf("%d", &n); //�Է�
//
//	for (i = 3; i <= n; i++) //3���� ����
//	{
//		fbo3 = fbo1 + fbo2; //fbo3�� fbo1+fbo2
//
//		step = fbo2; //step�� fbo2 ���� �־���
//		fbo2 = fbo3; //fbo2�� fbo3 ���� �־���
//		fbo1 = step; //fbo1�� step ���� �־���
//	}
//
//	printf("%d", fbo3); //fbo3 -> �Ǻ���ġ n��° �� ���
//
//	return 0;
//}