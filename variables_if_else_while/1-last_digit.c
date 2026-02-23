#include <stdlib.h>
#include <time.h>
/**
* main -Entry point
* Return: Lastdigit(0)
*/
int main(void)
{
	int n;
	int Lastd;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	Lastd = n % 10;

print ("Last digit of %d is %d", n, Lastd);

if (n > 5)
{
printf("%d and is greater than 5\n");
}
if (n == 0)
{
printf("and is 0\n");
}
if (n < 6 && n != 0)
{
printf("and is less than 6 and not 0\n");
}
	return (0);
}
