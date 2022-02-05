#include <stdio.h>

void Caesar(char* source, char* dest, int shift);

void main(void)
{
	char str1[256];
	char str2[256];
	int shift;

	printf("文字列を入力してください。 : ");
	scanf("%s", str1);

	printf("シフト数を入れてください。 : ");
	scanf("%d", &shift);

	Caesar(str1, str2, shift); printf("%s を変換した結果は %s です。\n", str1, str2);

	// 最後の入力待ち
	rewind(stdin);
	getchar(); 
} 

// シーザー暗号関数
void Caesar(char* source, char* dest, int shift)
{
	while (*source != '\0')
	{
		// まずアルファベットは一律変換
		if ((*source >= 'A' && *source <= 'Z') || (*source >= 'a' && *source <= 'z'))
		{
			*dest = *source + shift;

			// アルファベット一周したときの補正処理
			if ((*source >= 'A' && *source <= 'Z' && *dest > 'Z') || (*source >= 'a' && *source <= 'z' && *dest > 'z'))
				*dest -= 26;
		}
		else
			*dest = *source;

		source++;
		dest++;
	}

	*dest = '\0';
}