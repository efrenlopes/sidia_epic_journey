#include <stdio.h>

int main() {
	int s, v1, v2;
	float t;
	while( scanf("%d%d%d", &s, &v1, &v2) != EOF ) {
		if ( v1 > v2) {
			t = (float)s/(v1-v2);
			printf("%.2f\n", t);
		} else
			printf("impossivel\n");
	}
	return 0;
}
