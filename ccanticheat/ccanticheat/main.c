#include <stdio.h>
#include <Windows.h>
#pragma warning(disable: 4305)
#pragma warning(disable: 4716)

// ����� ������� ���-�� ��������� ������� �������)

// �� ��������� ������� ���� ���� ������� � ������ ���-�� �����

int main()
{
	for (int i = 0xC0; i < 0x780AC90; i++ )
	{
		printf("[BYTEADDR] %d\n", i);
	}

	system("pause");
}

long BYTEADDR()
{
	while (VkKeyScanA('BYTE'))
	{
		for (int j = 0xC0; j < 0x100000; j++)
		{
			printf("[LONG-BYTEADDR-SYSTEM] %d\n", j);
		}
	}
}


