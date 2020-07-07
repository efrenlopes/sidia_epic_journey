#include <stdio.h>

int main() {
	char s[1001];
	int n, i, c, rec[25];
	scanf("%d", &n);
	while(n--) {
		for(i=0; i<25; i++) rec[i]=0;
		scanf(" %[^\n]", s);
		i= c = 0;
		while(s[i] != '\0') {
			if (s[i]>='a' && s[i]<='z')
				rec[s[i]-'a']++;
			i++;
		}
		for(i=0; i<25; i++)
			if (rec[i] != 0) c++;

		if (c == 25)
			printf("frase completa\n");
		else if (c >= 13)
			printf("frase quase completa\n");
		else
			printf("frase mal elaborada\n");
	}
	return 0;
}
