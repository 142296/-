#include<windows.h>						//2010打开，中文ANSI编码     Unicode 改为多字符
#include<process.h>
#include<io.h>
#include<time.h>
#include<atlbase.h>
#include<sapi.h>
#include<sphelper.h>
#include<string.h>
#include <stdio.h>
#include <conio.h>

int scanfSentence(FILE* fp, char sentence[]);
int IgnoreRead(char sentence[]);
int StringSearch(char AreaString[], char ObjectString[]);
void IgnorePrint(char sentence[], char CharPointer[50][100], int num);
void IgnoreStore(FILE* fp, char sentence[], char CharPointer[50][100], int num);

CComPtr<ISpVoice> pVoice;
HRESULT hr;
int InitVoice();
void Speak(char* Txt);
void ReleaseVoice();
int OnlyRead();
int SkipWords();
int ReadFiles();
int main()
{
	if (!InitVoice())
		return 1;
	char ch;
loop:
	printf("\n\n\t请按任意键开始\n");
	_getch();
	system("cls");
	printf("		********************************\n");
	printf("		**     1: 只读文章            **\n");
	printf("		**     2: 屏蔽词处理          **\n");
	printf("		**     3: 朗读目录            **\n");
	printf("		**		   4: 退出                **\n");
	printf("		********************************\n");
	printf("                                        \n");
	printf("                                        \n");
	printf("	请选择输入选项[ 1 \\ 2 \\ 3 \\ 4 ] : >");
	while (ch = _getch())
	{
		printf("\n");
		switch (ch)
		{
		case '1':     OnlyRead(); goto loop;
		case '2':     SkipWords(); goto loop;
		case '3':     ReadFiles(); goto loop;
		case '4':     ReleaseVoice(); return 0;
		}
	}
	goto loop;
}

int OnlyRead()
{
	FILE* fp;
	char sentence[1024];
	char FileName[50];
	printf("请输入等待朗读的文件的名称（包括后缀）\n");
	gets(FileName);
	if ((fp = fopen(FileName, "r")) == NULL)
	{
		printf("文件打开失败...");
		_getch();
		return 1;
	}
	while (scanfSentence(fp, sentence) == 0)
	{
		printf("%s", sentence);
		IgnoreRead(sentence);
	}
	return 0;
}

int SkipWords()
{
	char sentence[1024];
	int i;
	int num;
	char CharPointer[50][100];
	FILE* fp;
	FILE* fRp;
	FILE* fMp;
	char FileRead[50];
	char FileResult[50];
	printf("请输入等待朗读的文件的名称（包括后缀）\n");
	gets(FileRead);
	if ((fp = fopen(FileRead, "r")) == NULL)
	{
		printf("文件打开失败...");
		_getch();
		return 1;
	}
	printf("请输入保存屏蔽处理结果的文件的名称（包括后缀）\n");
	gets(FileResult);
	if ((fRp = fopen(FileResult, "w")) == NULL)
	{
		printf("文件创建失败...");
		_getch();
		return 1;
	}
	if ((fMp = fopen("MaskWord.dat", "w")) == NULL)
	{
		printf("文件创建失败...");
		_getch();
		return 1;
	}
	printf("请输入需要屏蔽的词的数目\n");
	scanf("%d%*c", &num);
	for (i = 0; i < num; i++)
	{
		gets(CharPointer[i]);
	}
	fprintf(fMp, "%d\n", num);
	for (i = 0; i < num; i++)
	{
		fprintf(fMp, "%s", CharPointer[i]);
		if (i < num - 1)
			fprintf(fMp, " ");
		else
			fprintf(fMp, "\n");
	}
	fclose(fMp);
	while (scanfSentence(fp, sentence) == 0)
	{
		IgnorePrint(sentence, CharPointer, num);
		IgnoreStore(fRp, sentence, CharPointer, num);
		IgnoreRead(sentence);
	}
	return 0;
}

int ReadFiles()
{
	int i;
	char FileName[50];
	char CharPointer[50][100];
	char sentence[1024];
	char filesName[50];
	int num;
	char ch;
	FILE* fMp;
	FILE* fp;
	struct _finddata_t c_file;
	long hFile;
	printf("请输入文件夹名\n");
	gets(filesName);
	if ((fMp = fopen("MaskWord.dat", "r")) == NULL)
	{
		printf("文件打开失败...");
		_getch();
		return 1;
	}
	fscanf(fMp, "%d", &num);
	while ((ch = fgetc(fMp)) != '\n')
	{
		;
	}
	for (i = 0; i < num; i++)
	{
		fscanf(fMp, "%s", CharPointer[i]);
	}
	fclose(fMp);
	SetCurrentDirectory(filesName);
	i = 2;
	if ((hFile = _findfirst("*.txt", &c_file)) == -1)
	{
		printf("No found any *.txt files!\n");
	}
	else
	{
		printf("\n\n第 1个文件\t文件名:\t%s\n\n开始朗读 >>>>\n\n\n", c_file.name);
		strcpy(FileName, c_file.name);
		if ((fp = fopen(FileName, "r")) == NULL)
		{
			printf("文件打开失败...");
			_getch();
			return 1;
		}
		while (scanfSentence(fp, sentence) == 0)
		{
			IgnorePrint(sentence, CharPointer, num);
			IgnoreRead(sentence);
		}
		fclose(fp);
	}
	while (_findnext(hFile, &c_file) == 0)
	{
		printf("\n\n\n第%2d个文件\t文件名:\t%s\n\n开始朗读 >>>>\n\n\n", i++, c_file.name);
		strcpy(FileName, c_file.name);
		if ((fp = fopen(FileName, "r")) == NULL)
		{
			printf("文件打开失败...");
			_getch();
			return 1;
		}
		while (scanfSentence(fp, sentence) == 0)
		{
			IgnorePrint(sentence, CharPointer, num);
			IgnoreRead(sentence);
		}
		fclose(fp);

	}
	_findclose(hFile);
	return 0;
}
// 以下为自定义公共函数

//句子读取函数
int scanfSentence(FILE* fp, char sentence[])
{
	int j;
	char GetAChar; // 获取的字符
	int i = 0; //  句子的字节序号
	for (j = 0; j < 2; j++)
	{
		if (feof(fp))
		{
			sentence[i++] = 0;
			return 1;
		}
		sentence[i++] = GetAChar = fgetc(fp);

	}

	while (!feof(fp))
	{
		if (StringSearch((sentence + i - 2), "。") == 1)
		{
			sentence[i] = 0;
			return 0;
		}
		sentence[i++] = fgetc(fp);
	}
	sentence[i] = 0;
	return 0;
}

int IgnoreRead(char sentence[])
{
	int found = 0;
	int amount = 0;
	char* str = sentence;
	char IgnoreAmount[20];
	int IsChinese = 0;
	int IsEnglish = 0;
	do
	{
		if ((IsChinese = StringSearch(str, "（"))
			|| (IsEnglish = StringSearch(str, "(")))
		{
			found = 1;
			amount = 0;
			if (IsChinese == 1)
			{
				*str = 0;
				str += 2;
				Speak(sentence);
				while (StringSearch(str, "）") == 0)
				{
					if (*str > 0)
					{
						str++;
						amount++;
					}
					if (*str < 0)
					{
						str++;
						str++;
						amount++;
					}
				}
				str += 2;
				sprintf(IgnoreAmount, "此处省略%d个字",
					amount);
				Speak(IgnoreAmount);
				IgnoreRead(str);
			}
			else
			{
				*str = 0;
				str++;
				Speak(sentence);
				while (StringSearch(str, ")") == 0)
				{
					if (*str > 0)
					{
						str++;
						amount++;
					}
					if (*str < 0)
					{
						str++;
						str++;
						amount++;
					}
				}
				str++;
				sprintf(IgnoreAmount, "此处省略%d个字", amount);
				Speak(IgnoreAmount);
				IgnoreRead(str);
			}
		}
	} while (*str++);
	if (found == 0)
	{
		Speak(sentence);
	}
	return 0;
}

// 用于判断  参数 1  是否 以  参数 2  为开头，是返回 1，否返回 0
int StringSearch(char AreaString[], char ObjectString[])
{
	int i;
	int len;
	len = strlen(ObjectString);
	for (i = 0; i < len; i++)
	{
		if (AreaString[i] != ObjectString[i])
		{
			return 0;
		}
	}
	return 1;
}

void IgnorePrint(char sentence[], char CharPointer[50][100], int num)
{
	int i;
	int j = 0;
	{
		while (sentence[j])
		{
			for (i = 0; i < num; i++)
			{
				if (StringSearch(sentence + j, CharPointer[i]) == 1)
				{
					printf("(%s)", CharPointer[i]);
					j += (strlen(CharPointer[i]));
					break;
				}
			}
			printf("%c", sentence[j]);
			j++;
		}
	}
}

void IgnoreStore(FILE* fp, char sentence[], char CharPointer[50][100], int num)
{
	int i;
	int j = 0;
	{
		while (sentence[j])
		{
			for (i = 0; i < num; i++)
			{
				if (StringSearch(sentence + j, CharPointer[i]) == 1)
				{
					fprintf(fp, "(%s)", CharPointer[i]);
					j += (strlen(CharPointer[i]));
					break;
				}
			}
			fprintf(fp, "%c", sentence[j]);
			j++;
		}
	}
}
// 以下为语音相关函数定义

//初始化语音阅读工具
int InitVoice()
{
	CComPtr<IEnumSpObjectTokens> pEnum;
	CComPtr<ISpObjectToken> pVoiceToken;
	int i;
	::CoInitialize(NULL);
	if (FAILED(hr = SpEnumTokens(SPCAT_VOICES, L"Language=804", NULL, &pEnum)))
		return 0;
	for (i = 0; i < 1; i++)		//这里可以根据已安装的语音库，多循环几次以变更语音
	{
		pVoiceToken.Release();
		pEnum->Next(1, &pVoiceToken, NULL);
	}
	if (FAILED(hr = pVoice.CoCreateInstance(CLSID_SpVoice)))
		return 0;
	if (FAILED(hr = pVoice->SetVoice(pVoiceToken)))
		return 0;
	return 1;

}

//语音读字符串
void Speak(char* Txt)
{
	CSpDynamicString  s(Txt);
	pVoice->Speak(s, 0, 0);
}
//释放缓冲
void ReleaseVoice()
{
	pVoice.Release();
	CoUninitialize();
}


