#include<stdio.h>
#define pi 3.1415926

int main()
{
	//const float pi = 3.1415926;
	float r,h,l,v;
	scanf("%f %f",&r,&h);
	l = 2*pi*r;
	v = pi*r*r*h;

	printf("圆的周长是：%6.2f\n",l);
	printf("圆的体积是：%6.2f\n",v);
	return 0;
}
