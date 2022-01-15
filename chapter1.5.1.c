#include <stdio.h>

#define IN 1
#define OUT 0

void worldCounting(long *nw, long *nl, long *nc);

int main()
{
	printf("The value of EOF is:\n");
	printf("%d\n", EOF);
	/*the above is some testing text.*/
	int c;
	while((c = getchar()) != EOF){
		putchar(c);
	}

	/*world, newline, character count.*/
	// long nw, nl, nc;
	// nw = nl = nc = 0;
	// worldCounting(&nw, &nl, &nc);

	return 0;
}

void worldCounting(long *nw, long *nl, long *nc)
{
	int c, state = OUT;
	while((c = getchar()) != EOF){
		(*nc)++;

		if (c == '\n'){
			(*nl)++;
		}

		if (c == '\n' || c == ' ' || c == '\t'){
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			(*nw)++;
		}
	}
}
