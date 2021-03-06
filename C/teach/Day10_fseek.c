#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//掌握main函数的传参
int main(int argc, char* argv[])	//参数的数量、具体参数（本身的exe程序算第一个参数）
{
	int i;
	char c;
	FILE* fp;
	//for (i = 0; i < argc; i++)	//输出参数
	//{
	//	puts(argv[i]);
	//}
	fp = fopen(argv[1], "r+");
	if (NULL == fp)
	{
		perror("fopen");
		goto error;
	}
	while ((c = fgetc(fp)) != EOF)
	{
		if (c >= 'A' && c <= 'Z')
		{
			c += 32;
			fseek(fp, -1, SEEK_CUR);
			fputc(c, fp);
		}
		fseek(fp, 0, SEEK_CUR);	//写读之间必须刷新位置指针
	}
	fclose(fp);
error:
	system("pause");
}