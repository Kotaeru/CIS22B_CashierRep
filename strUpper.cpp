#include <cctype>


//********************************************
// strUpper function                         *
//********************************************
void strUpper(char* str)
{
	while (*str != 0)
	{
		*str = toupper(*str);
		str++;
	}
}