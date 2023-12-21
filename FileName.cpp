#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");

	FILE* fin;
	FILE* fout;
	fopen_s(&fin, "C:\\Users\\User\\Desktop\\¿ \\Temp\\Lab11_in.txt", "rt");
	fopen_s(&fout, "C:\\Users\\User\\Desktop\\¿ \\Temp\\Lab11_out.html", "wt");
	char str[256];
	fgets(str, 256, fin);
	fprintf(fout, "<HTML><HEAD><TITLE>%s</TITLE></HEAD><BODY><H1>%s<BR></H1>", str, str);

	while (!feof(fin)) {
		fgets(str, 256, fin);
		int i = 0;
		int flag = 0;
		int i_space = 0;
		while (str[i] != 0) {
			if (str[i] == 'A') {
				flag = 1;
			}
			if (str[i] == ' ') {
				if (flag == 1) {
					fprintf(fout, "<i><b>NOP </b></i>");
					i_space = i + 1;
				}
				else {
					for (int j = i_space; j <= i; j++) {
						fprintf(fout, "%c", str[j]);
					}
					i_space = i;
				}
				flag = 0;
			}
			i++;
		}
		if (flag == 1) {
			fprintf(fout, "<i><b>NOP</b></i>");
		}
		else {
			for (int j = i_space; j < i; j++) {
				fprintf(fout, "%c", str[j]);
			}
		}
		fprintf(fout, "<BR>", str);
	}

	fprintf(fout, "</BODY></HTML>");
	fclose(fin);
	fclose(fout);

	return 0;
}