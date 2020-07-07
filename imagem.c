#include <stdio.h>

int main() {
	int n=1, m=1, a, b, i, j, x, y;
	char p[100][50];
	scanf("%d%d", &n, &m);
	while( n!=0 && m!=0) {

		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				scanf(" %c", &p[i][j]);
			}
		}
		
		scanf("%d%d", &a, &b);
		a = a/n;
		b = b/m;

		for(i=0; i<n; i++) {
			for(x=0; x<a; x++) {
				for(j=0; j<m; j++) {
					for(y=0; y<b; y++)
						printf("%c", p[i][j]);
				}
				printf("\n");
			}
		}
        printf("\n");
		scanf("%d%d", &n, &m);
	}
	return 0;
}
