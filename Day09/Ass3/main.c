//#include<stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"

int main(){
	printf("Area of Circle: %d\n", carea(5));
	
	printf("Perimeter of Circle: %d\n", cperi(5));

	printf("Area of Square: %d\n", sarea(4));

	printf("Perimeter of Square: %d\n", speri(4));

	printf("Area of Rectangle: %d\n", rarea(3,2));

	printf("Perimeter of Rectangle: %d\n", rperi(3,2));

}
