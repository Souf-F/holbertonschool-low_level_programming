#include <stdlib.h>
#include <time.h>
/**
* main -Entry point
* Return: Lastdigit(0)
*/
int main(void)
{
	int n;
	int lastd;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastd = n % 10;


if (n > 5)
{
print("Last digit of %d is %d and is less than 6 and not 0", n, lastd);
}
if (n == 0)
{
printf("Last digit of %d is %d and is greater than 5", n, lastd);
}
if (n < 5 && n != 0)
{
printf("Last digit of %d is %d and is 0", n, lastd);
}
	return (0);
}
