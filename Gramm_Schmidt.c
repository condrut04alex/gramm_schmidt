#include <stdio.h>
#include <math.h>

float 
f[][5]={   {0,0,0,0,0},
		{0,1,0,0,0},   
	 	{0,0,1,0,0}, 
		{0,0,0,1,0},  
		{0,0,0,0,1}},


/*f[][5]={   {0,0,0,0,0},
		{0,2,-1,-2,1},   
	 	{0,3,-2,3,2}, 
		{0,-1,0,1,2},  
		{0,2,1,1,1}},*/
  
      g[5][5];

float calc_numarator(int k, int i)
{
	int x; float prod=0;
	for(x=1; x<=4; x++)
	{	
		prod=prod+f[k][x]*g[i][x];
		
	}
	printf("prod_x=%f ", prod);	;	 
	return prod;
}

float calc_numitor(int i)
{
	int x;
	float prod=0;
	for(x=1; x<=4; x++)
		prod=prod+g[i][x]*g[i][x];
	printf("prod_y=%f",prod);

	return prod;
}

float lambda(int k,int i)
{
	float x,y;
   
   x=calc_numarator(k, i);
   y=calc_numitor(i);
   printf("\nk=%i i=%i x=%f y=%f\n", k, i, x, y);
   return x/(y*(-1)) ; 
}


void pas_1(){
int i;
for(i=1;i<=4;i++)
  g[1][i]=f[1][i];
   
}
void pas_2()
{
	int x;
	float l;
	l=lambda(2, 1);
	for(x=1; x<=4; x++)
		g[2][x]=f[2][x]+l*g[1][x];
 
}

void pas_3()
{

	float l31, l32;
	 int x;
	l31=lambda(3, 1);
	l32=lambda(3, 2);
	for(x=1; x<=4; x++)
		g[3][x]=f[3][x]+l31*g[1][x]+l32*g[2][x];
}

void pas_4()
{
	float l41, l42, l43;
	 int x;

	l41=lambda(4,1);
	l42=lambda(4,2);
	l43=lambda(4,3);
	for(x=1; x<=4; x++)
		g[4][x]=f[4][x]+l41*g[1][x]+l42*g[2][x]+l43*g[3][x];

}




int main(){
 int i,j;
/*   for(i=1;i<5;i++)
	for(j=1;j<=4;j++)
		{
		printf("f[%i][%i]=",i,j);
		scanf("%f",&f[i][j]);
	}*/

pas_1();

printf("g1=(");
for(i=1; i<=4; i++)
{
	printf("%f", g[1][i]);
	if(i!=4)
		printf(", ");
}
printf(")\n");

pas_2();

printf("l21=%f\n",lambda(2,1));

printf("g2=(");
for(i=1; i<=4; i++)
{
	printf("%f", g[2][i]);
	if(i!=4)
		printf(", ");
}
printf(")\n");


pas_3();
printf("g3=(");
for(i=1; i<=4; i++)
{
	printf("%f", g[3][i]);
	if(i!=4)
		printf(", ");
}
printf(")\n");

printf("l31=%f\n",lambda(3,1));
printf("l32=%f\n",lambda(3,2));

printf("\n");


pas_4();

printf("g4=(");
for(i=1; i<=4; i++)
{
	printf("%f", g[4][i]);
	if(i!=4)
		printf(", ");
}
printf(")\n");
printf(" l41=%f\n",lambda(4,1));
printf(" l42=%f\n",lambda(4,2));
printf(" l43=%f\n",lambda(4,3));

printf("\n");


return 0;
}
