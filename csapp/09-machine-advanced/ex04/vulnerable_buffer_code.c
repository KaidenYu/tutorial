#include <stdio.h>

/* Echo Line */
void echo()
{
	char buf[4];
	gets(buf);
	puts(buf);
}

void call_echo() {
	echo();
}

int main(int argc, char** argv)
{
	call_echo();

	return 0;
}