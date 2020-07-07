#include <stdio.h>
#include <stdlib.h>

int cmp_asc (const void * n, const void * m) {
	return ( *(int*)n - *(int*)m );
}

int cmp_desc (const void * n, const void * m) {
	return ( *(int*)m - *(int*)n );
}

void intToArray(int x, int v[4]) {
	int i;
	for(i=3; i>=0; i--) {
		v[i] = x % 10;
		x = x / 10;
	}
}

int arrayToInt(int v[4]) {
	int i, n=0;
	for(i=0; i<4; i++)
		n = n*10 + v[i];
	return n;
}

int maior_numero_com_digitos_de(int x){
	int v[4];
	intToArray(x, v);
	qsort(v, 4, sizeof(int), cmp_desc);
	return arrayToInt(v);
}

int menor_numero_com_digitos_de(int x) {
	int v[4];
	intToArray(x, v);
	qsort(v, 4, sizeof(int), cmp_asc);
	return arrayToInt(v);
}

int krapekar(int x) {
	int cnt=0;
	while (x != 6174) {
		int maior = maior_numero_com_digitos_de(x);
		int menor = menor_numero_com_digitos_de(x);
		x = maior - menor;
		cnt = cnt + 1;
		if (cnt == 8) return -1;
	}
	return cnt;
}

int main() {
	int n, x, k, c=0;
	scanf("%d", &n);
	while(c++ < n) {
		scanf("%d", &x);
		k = krapekar(x);
		printf("Caso #%d: %d\n", c, k);
	}
	return 0;
}
