#include <stdio.h>
#include <locale.h>
#include <windows.h>

struct MyStructs {
	int X, Y, R, G, B, F;
	char S[256];
};

int main() {
	setlocale(LC_ALL, "Russian.1251");

	int N;
	printf("������� ���������� �����: ");
	scanf_s("%d", &N);

	FILE* f;
	fopen_s(&f, "C:\\Users\\User\\Desktop\\��\\Temp\\mystructs.bin", "wb");
	fwrite(&N, sizeof(int), 1, f);
	for (int i = 0; i < N; i++) {
		MyStructs p;
		printf("������� ��������� ������� N%d: \n", i + 1);
		printf("X = ");
		scanf_s("%d", &p.X);
		printf("Y = ");
		scanf_s("%d", &p.Y);
		printf("����� ������� = ");
		gets_s(p.S);
		gets_s(p.S);
		printf("���� RGB = ");
		scanf_s("%d%d%d", &p.R, &p.G, &p.B);
		printf("������ ������ = ");
		scanf_s("%d", &p.F);
		fwrite(&p, sizeof(MyStructs), 1, f);
	}
	fclose(f);
	return 0;
}