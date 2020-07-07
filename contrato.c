#include <stdio.h>

int main() {
	int i, j, started;
	char d, n[101], n2[101];
	while(1) {
		scanf(" %c %[^\n]", &d, n);
		if (d=='0' && n[0]=='0') break;
		i = j = 0;
		started = 0;
		while(n[i] != '\0') {
			if (n[i] != d && n[i] != '0') started = 1;
			if ( n[i] != d && !(n[i] == '0' && !started) )
				n2[j++] = n[i];
			i++;
		}
		n2[j] = '\0';
		if (j == 0)
			printf("0\n");
		else
			printf("%s\n", n2);
	}
	return 0;
}
