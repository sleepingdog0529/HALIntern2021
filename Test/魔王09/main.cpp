#include <stdio.h>

void Caesar(char* source, char* dest, int shift);

void main(void)
{
	char str1[256];
	char str2[256];
	int shift;

	printf("���������͂��Ă��������B : ");
	scanf("%s", str1);

	printf("�V�t�g�������Ă��������B : ");
	scanf("%d", &shift);

	Caesar(str1, str2, shift); printf("%s ��ϊ��������ʂ� %s �ł��B\n", str1, str2);

	// �Ō�̓��͑҂�
	rewind(stdin);
	getchar(); 
} 

// �V�[�U�[�Í��֐�
void Caesar(char* source, char* dest, int shift)
{
	while (*source != '\0')
	{
		// �܂��A���t�@�x�b�g�͈ꗥ�ϊ�
		if ((*source >= 'A' && *source <= 'Z') || (*source >= 'a' && *source <= 'z'))
		{
			*dest = *source + shift;

			// �A���t�@�x�b�g��������Ƃ��̕␳����
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