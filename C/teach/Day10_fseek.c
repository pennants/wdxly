#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����main�����Ĵ���
int main(int argc, char* argv[])	//���������������������������exe�������һ��������
{
	int i;
	char c;
	FILE* fp;
	//for (i = 0; i < argc; i++)	//�������
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
		fseek(fp, 0, SEEK_CUR);	//д��֮�����ˢ��λ��ָ��
	}
	fclose(fp);
error:
	system("pause");
}