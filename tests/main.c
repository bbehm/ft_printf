#include <stdio.h>
#include "../includes/ft_printf.h"
#include <limits.h>

int	main(void)
{
	int precision = 8;
	int biggerPrecision = 16;
	const char *greetings = "Hello world";

	ft_printf("***************** TESTING MIXED *******************\n\n");

	ft_printf("***************** TEST 1 *******************\n\n");
	ft_printf("This is a simple test.\nSecond sentence.\n");
	printf("This is a simple test.\nSecond sentence.\n");
	ft_printf("\n");

	ft_printf("***************** TEST 2 *******************\n\n");
	ft_printf("111%s\n", "222");
	printf("111%s\n", "222");
	ft_printf("\n");

 	ft_printf("***************** TEST 3 *******************\n\n");
	ft_printf("111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
	printf("111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
	ft_printf("\n");

	ft_printf("***************** TEST 4 *******************\n\n");
	ft_printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
	printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
	ft_printf("\n");

	ft_printf("***************** TEST 5 *******************\n\n");
	ft_printf("%p\n", 0);
	printf("%p\n", 0);
	ft_printf("\n");

	ft_printf("***************** TEST 6 *******************\n\n");
	ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	ft_printf("\n");

	ft_printf("***************** TEST 7 *******************\n\n");
	printf("s: %s, p: %p, d:%d\n", "a string", &precision, 42);
	printf("s: %s, p: %p, d:%d\n", "a string", &precision, 42);
	ft_printf("\n");

	ft_printf("***************** TEST 8 *******************\n\n");
	ft_printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
	printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
	ft_printf("\n");

	ft_printf("***************** TEST 9 *******************\n\n");
	ft_printf("a%Xb%Xc%Xd\n", 0, 55555, 100000);
	printf("a%Xb%Xc%Xd\n", 0, 55555, 100000);
	ft_printf("\n");

	ft_printf("***************** TEST 10 *******************\n\n");
	ft_printf("%c%c\n", '4', '2');
	printf("%c%c\n", '4', '2');
	ft_printf("\n");

	ft_printf("***************** TEST 11 *******************\n\n");
	ft_printf("%ld\n", (long)INT_MIN - 1);
	printf("%ld\n", (long)INT_MIN - 1);
	ft_printf("\n");

	ft_printf("***************** TEST 12 *******************\n\n");
	ft_printf("%llx, %llx\n", 0llu, ULLONG_MAX);
	printf("%llx, %llx\n", 0llu, ULLONG_MAX);
	ft_printf("\n");

	ft_printf("***************** TEST 13 *******************\n\n");
	ft_printf("%hu, %hu\n", 0, USHRT_MAX);
	printf("%hu, %hu\n", 0, USHRT_MAX);
	ft_printf("\n");

	ft_printf("***************** TEST 14 *******************\n\n");
	ft_printf("%hhd\n", CHAR_MAX);
	printf("%hhd\n", CHAR_MAX);
	ft_printf("\n");

	ft_printf("***************** TEST 15 *******************\n\n");
	printf("{%-15p}\n", 0);
	printf("{%-15p}\n", 0);
	ft_printf("\n");

	ft_printf("***************** TEST 16 *******************\n\n");
	ft_printf("{%30d}\n", 10000);
	printf("{%30d}\n", 10000);
	ft_printf("\n");

	ft_printf("***************** TEST 17 *******************\n\n");
	ft_printf("{%-15p}\n", 0);
	printf("{%-15p}\n", 0);
	ft_printf("\n");

	ft_printf("***************** TEST 18 *******************\n\n");
	ft_printf("%#o\n", INT_MAX);
	printf("%#o\n", INT_MAX);
	ft_printf("\n");

	ft_printf("***************** TEST 19 *******************\n\n");
	ft_printf("%+i\n", -42);
	printf("%+i\n", -42);
	ft_printf("\n");

	ft_printf("***************** TEST 20 *******************\n\n");
	ft_printf("% i\n", -9999);
	printf("% i\n", -9999);
	ft_printf("\n");

	ft_printf("***************** TEST 21 *******************\n\n");
	ft_printf("%8.4d\n", 424242424);
	printf("%8.4d\n", 424242424);
	ft_printf("\n");

	ft_printf("***************** TEST 22 *******************\n\n");
	ft_printf("%8.4o\n", 424242424);
	printf("%8.4o\n", 424242424);
	ft_printf("\n");

	ft_printf("***************** TEST 23 *******************\n\n");
	ft_printf("%.4s\n", "42");
	printf("%.4s\n", "42");
	ft_printf("\n");

	ft_printf("***************** TEST 24 *******************\n\n");
	ft_printf("%.5c\n", 42);
	printf("%.5c\n", 42);
	ft_printf("\n");

	ft_printf("***************** TEST 25 *******************\n\n");
	ft_printf("%2.9p\n", 1234);
	printf("%2.9p\n", 1234);
	ft_printf("\n");

	ft_printf("***************** TEST 26 *******************\n\n");
	ft_printf("{%f}{%lf}{%Lf}\n", -1.42, -1.42, -1.42l);
	printf("{%f}{%lf}{%Lf}\n", -1.42, -1.42, -1.42l);
	ft_printf("\n");

// testing the * flag (BONUS) 

	ft_printf("***************** TESTING * BONUS *******************\n\n");

	ft_printf("***************** TEST 1 *******************\n\n");
	ft_printf("|%.8s|\n", greetings);
	printf("|%.8s|\n", greetings);
	ft_printf("\n");

	ft_printf("***************** TEST 2 *******************\n\n");
	ft_printf("|%.*s|\n", precision , greetings);
	printf("|%.*s|\n", precision , greetings);
	ft_printf("\n");
	
	ft_printf("***************** TEST 3 *******************\n\n");
	ft_printf("|%16s|\n", greetings);
	printf("|%16s|\n", greetings);
	ft_printf("\n");

	ft_printf("***************** TEST 4 *******************\n\n");
	ft_printf("|%*s|\n", biggerPrecision , greetings);
	printf("|%*s|\n", biggerPrecision , greetings);
	ft_printf("\n");

	ft_printf("***************** TEST 5 *******************\n\n");
	ft_printf("{%*c}\n", 0, 0);
	printf("{%*c}\n", 0, 0);
	ft_printf("\n");

	ft_printf("***************** TEST 6 *******************\n\n");
	ft_printf("%*.*d\n", 0, 3, 0);
	printf("%*.*d\n", 0, 3, 0);
	ft_printf("\n");

	ft_printf("***************** TEST 7 *******************\n\n");
	ft_printf("{%05.*d}\n", -15, 42);
	printf("{%05.*d}\n", -15, 42);
	ft_printf("\n");

	return (0);
}