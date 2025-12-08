#include <stdio.h>

int main()
{
	int one;
	int two;
	int five;
	
	for (one=1; one<100; one++) {
		for (two=1; two*2<100; two++){
			for (five=1; five*3<100; five++){
				if (one + two*2 + five*5 == 100){
					printf("%d个一角，%d个二角和%d个五角可以凑出10元\n", one, two, five);
				}
			}
		}
	}
	
	return 0;
}
