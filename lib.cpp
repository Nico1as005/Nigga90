int my_strlen(char* str) {
	int i = 0;
	while (str[i] != 0) {
		i++;
	}
	return i;
}

void my_strcpy(char* str1, char* str2) {
	int i = 0;
	while (str2[i] != 0) {
		str1[i] = str2[i];
		i++;
	}
	str1[i] = 0;
}

void my_strcat(char* str1, char* str2) {
	int i = 0;
	int n = my_strlen(str1);
	while (str2[i] != 0) {
		str1[n + i] = str2[i];
		i++;
	}
	str1[n + i] = 0;
}

int my_strcmp(char* str1, char* str2) {
	int i = 0;
	while (str1[i] != 0 || str2[i] != 0) {
		if (str2[i] - str1[i] != 0) {
			return str2[i] - str1[i];
		}
		i++;
	}
	return 0;
}

char* my_strchr(char* str, char c) {
	int i = 0;
	while (str[i] != 0) {
		if (str[i] == c) {
			return &str[i];
		}
		i++;
	}
	return nullptr;
}

char* my_strstr(char* str1, char* str2) {
	int i = 0;
	int n = my_strlen(str2);
	while (str1[i] != 0) {
		if (str1[i] == str2[0]) {
			for (int j = 0; j <= n; j++) {
				if ((str1[i + j] == 0 || str1[i + j] != str2[j]) && str2[j] != 0) {
					break;
				}
				if (str1[i + j] != str2[j] || str1[i + j] == 0 && str2[j] == 0) {
					return &str1[i];
				}
			}
		}
		i++;
	}
	return nullptr;
}