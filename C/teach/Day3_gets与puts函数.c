#include <stdio.h> 
#include <stdlib.h> 

//gets与puts
//gets会在最后添一个\0
//gets也不安全，不能保证不越界
int main()
{
	char c[50];
	while (gets(c)!=NULL)	//按Ctrl+Z结束
	{
		puts(c);	//等价于printf("%s\n", c);
	}
	system("pause");
}
