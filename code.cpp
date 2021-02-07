#include<stdio.h>
#include<math.h>
#include <stdlib.h>
float Analytical()
{
 float a;
 a = cos(0/4) - cos(M_PI/4);
 return a;
}
float Monte_Carlo()
{
 float sum = 0;
 int i;
 int j;
 float x;
 int Values_n[] = {10,20,30,40,50,100};
 int n;
 n = sizeof Values_n / sizeof Values_n[0]; //length of Values_n array
 float Y_n[n]; // Array for saving Monte Carlo result
 float div[n]; // Array for saving Diversion from analytical result
 for(i=0;i<n;i++)
 {
 sum = 0;
 for(j=1;j<(Values_n[i]+1);j++)
 {
 // Uniform random number within range 0 to pi/4
 x=((long double)rand()/RAND_MAX)*(M_PI/4-0) + 0;
 sum += sin(x);
 }
 // calculation Monte Carlo result
 float y = (M_PI/4 - 0)*sum/Values_n[i];
 Y_n[i]=y;
 printf("\n %f ",y);
 float analytical_result = Analytical();
 div[i]= analytical_result - y ;
 printf("Diversion from analytical result %f ",div[i]);
 }
}
int main()
{
 float a;
 a=Analytical();
 printf("Analytical Result %f",a);
 Monte_Carlo();
}
