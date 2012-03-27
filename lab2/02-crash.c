#include <stdlib.h>

int main(int argc, char** argv)
{
	char* a = 0;
	char b = *a;
	b = b;
	return 0;
}
