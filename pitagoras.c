#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
	int r;
	do {
		r = a%b;
		a = b;
		b = r;
	} while( b!=0 );
	return a;
}

int cmp(const void * n, const void * m) {
	return ( *(int*)m - *(int*)n );
}

int main() {
	int v[3];
	while( scanf("%d%d%d", &v[0], &v[1], &v[2]) != EOF ) {
		qsort(v, 3, sizeof(int), cmp);
		if ( v[0]*v[0] == v[1]*v[1]+v[2]*v[2]) {
			if ( mdc(v[0], mdc(v[1], v[2])) == 1 )
				printf("tripla pitagorica primitiva\n");
			else
				printf("tripla pitagorica\n");
		} else
			printf("tripla\n");
	}
	return 0;
}
