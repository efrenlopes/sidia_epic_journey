#include <stdio.h>
#include <limits.h>

typedef struct coord_s {
	int row;
	int col;
} coord;

typedef struct vertex_s {
	coord a;
	coord b;
	int parent;
	int visited;
	int adj[5000];
	int n_adj;
} vertex;

void set_a(vertex* v, int row, int col) {
	v->a.row = row;
	v->a.col = col;
	v->parent = -1;
}

void set_b(vertex* v, int row, int col) {
	v->b.row = row;
	v->b.col = col;
}

int intersect(vertex l, vertex r) {
	if (l.a.col <= r.a.col && l.b.col >= r.a.col
			&&
			r.a.row <= l.a.row && r.b.row >= l.a.row)
		return 1;
	return 0;
}


#define M 100
#define MAX 5000
char m[M][M];
vertex vertices[MAX];
int graph[MAX][MAX];
int queue[MAX];

int bfs(int s, int t, int V) {
	int i, v, top=-1;
	for(i=0; i<V; i++) vertices[i].visited=0;
	//iniciando o vértice source
	vertices[s].parent = -1;
	vertices[s].visited = 1;
	queue[++top] = s;
	//Laço do BFS
	while (top != -1) {
		int u = queue[top--];
		for (v=0; v<V; v++) {
			if (vertices[v].visited==0 && graph[u][v] > 0) {
				queue[++top] = v;
				vertices[v].parent = u;
				vertices[v].visited = 1;
			}
		}
	}
	return vertices[t].visited; //retorna se o sink foi visitado
}

int main() {
	int n, V, ill;
	int i, j;
	char c;

	while( scanf(" %d", &n) != EOF ) {
		//lendo a entrada
		for( i=0; i<n; i++ )
			for( j=0; j<n; j++ )
				scanf(" %c", &m[i][j]);

		//Criando o vértice source (s), ele ocupa a primeira posição
		V = 0;
		vertices[V].parent = -1;

		//separando por linhas (vertices esquerdos do grafo bipartido)
		for( i=0; i<n; i++ ){
			c = 'X';
			for( j=0; j<n; j++ ){
				if ( c != m[i][j] ) {
					if (c == 'X') {
						V++;
						set_a(&vertices[V], i, j );
					} else
						set_b(&vertices[V], i, j-1);
					c = m[i][j];
				}
			}
			if (c == '.') set_b(&vertices[V], i, j-1);
		}
		ill = V; //ill marca a posição do último vértice da esquerda



		//separando por colunas (vertices direito do grafo bipartido)
		for( j=0; j<n; j++ ){
			c = 'X';
			for( i=0; i<n; i++ ){
				if ( c != m[i][j] ) {
					if (c == 'X') {
						V++;
						set_a(&vertices[V], i, j );
					} else
						set_b(&vertices[V], i-1, j);
					c = m[i][j];
				}
			}
			if (c == '.') set_b(&vertices[V], i-1, j);
		}



		//Criando o vértice sink (t), ele ocupa a última posição
		V++;
		vertices[V].parent = -1;
		V++; //a partir daqui V é a quantidade de vértices, incluindo o source e o sink

		//Gerando o grafo com as devidas arestas
		for(i=1; i<=ill; i++) {
			graph[0][i] = 1;
			for(j=ill+1; j<V-1; j++) {
				graph[i][j] = intersect(vertices[i], vertices[j]);
				graph[j][V-1] = 1;
			}
		}

		int v, u, s=0, t=V-1;
		int max_flow = 0, path_flow = INT_MAX;
		while (bfs(s, t, V)) {

			v = t;
			while(v != s) {
				u = vertices[v].parent;
				path_flow = ( (path_flow <= graph[u][v]) ? path_flow : graph[u][v] );
				v = vertices[v].parent;
			}

			v = t;
			while( v != s ) {
				u = vertices[v].parent;
				graph[u][v] -= path_flow;
				graph[v][u] += path_flow;
				v = vertices[v].parent;
			}
			max_flow += path_flow;
		}

		printf("%d\n", max_flow);

	}
	return 0;
}
