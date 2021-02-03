#include<stdio.h>
// int main(){
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int(*p)[10] = &arr;
//     for (int i = 0; i < 10;i++){
//         printf("%d", (*p)[i]);
//     }
//     return 0;
// }
int main()
{
	int n = 9;
	//
	//0 00000000 00000000000000000001001
	//(-1)^0 * 0.00000000000000000001001 * 2^-126
	//
	float *pFloat = (float *)&n;
	printf("n的值为：%d\n", n);//9
	printf("*pFloat的值为：%f\n", *pFloat);//0.000000

	*pFloat = 9.0;
	//1001.0
	//(-1)^0 * 1.001*2^3
	//S=0
	//M=1.001
	//E=3     +127
	//01000001000100000000000000000000
	//
	printf("num的值为：%d\n", n);//直接打印整形时，就是2进制到十进制转换
	printf("*pFloat的值为：%f\n", *pFloat);//9.0
	return 0;
}

