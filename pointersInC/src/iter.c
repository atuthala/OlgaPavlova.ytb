#include <stdio.h>
#include <stdlib.h>

// TODO Вынести объявления в отдельный .h-файл

typedef struct metastr{
	int length;
	char* data;
} metastr;

typedef void (*cb)(char);

void run_callback(char);
void magic_run(metastr, cb);

int main()
{
	char c[] = "abcdefghi";
	metastr mts = {.length = 10, .data = c}; // не совсем верно

	for (int i = 0; i < 10; ++i)
	{
		run_callback(c[i]);
	}

	magic_run(mts, run_callback);

	// ??? MAGIC_RUN(@c@, !printf...!)

	// + size -- задаём длину
	// + '\0' -- это конец
	// *** как-то зашить размер в сами данные

	return 0;
}

void run_callback(char h) {
	printf("%c ", h);
}

void magic_run(metastr mts, cb rcb)
{
	for (int i = 0; i < mts.length; i++)
		rcb(mts.data[i]);
}