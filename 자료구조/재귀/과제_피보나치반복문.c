#include <stdio.h>
#pragma warning(disable : 4996)

int main(void)
{
	int n;
	int i;
	int fbo1 = 1; //피보나치의 첫번째는 1
	int fbo2 = 1; //피보나치의 두번째는 1
	int fbo3 = 1; //for문이 3부터 시작되는데 1,2가 입력되면 출력이 1이 되야함

	scanf("%d", &n); //입력

	for (i = 3; i <= n; i++) //3부터 시작
	{
		fbo3 = fbo1 + fbo2; //fbo3은 fbo1+fbo2

		fbo1 = fbo2; //fbo1에 fbo2 값을 넣어줌
		fbo2 = fbo3; //fbo2에 fbo3 값을 넣어줌
	}

	printf("%d", fbo3); //fbo3 -> 피보나치 n번째 값 출력

	return 0;
}

//int main(void) 내가 썻던 코드
//{
//	int n;
//	int i;
//	int fbo1 = 1; //피보나치의 첫번째는 1
//	int fbo2 = 1; //피보나치의 두번째는 1
//	int fbo3 = 1; //for문이 3부터 시작되는데 1,2가 입력되면 출력이 1이 되야함
//	int step = 0; //피보나치 수를 구할 때 사용해줄 변수
//
//	scanf("%d", &n); //입력
//
//	for (i = 3; i <= n; i++) //3부터 시작
//	{
//		fbo3 = fbo1 + fbo2; //fbo3은 fbo1+fbo2
//
//		step = fbo2; //step에 fbo2 값을 넣어줌
//		fbo2 = fbo3; //fbo2에 fbo3 값을 넣어줌
//		fbo1 = step; //fbo1에 step 값을 넣어줌
//	}
//
//	printf("%d", fbo3); //fbo3 -> 피보나치 n번째 값 출력
//
//	return 0;
//}