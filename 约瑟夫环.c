#include <stdlib.h>

typedef struct node* link;
struct node
{
	int item;
	link next;
};
// N个人围成一圈，第一个报数，第M个被杀掉

main( int argc, char* argv[] )
{
	int i, N = 9, M = 5;
	link t = malloc(sizeof *t), x = t;
	t->item = 1;
	t->next = t;
	for( i=2; i<=N; i++ )
	{
		x = (x->next = malloc(sizeof *x));
		x->item = i;
		x->next = t;
	}
	while( x != x->next )
	{
		for( i=1; i<M; i++ )
		{
			x = x->next;
		}
		x->next = x->next->next;
		N --;
	}
	printf("%d\n", x->item);
}