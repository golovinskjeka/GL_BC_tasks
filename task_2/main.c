/* HomeWork 2. Variant 3 
-------------------
z1 = cos(a)+sin(a)+cos(3a)+sin(3a)
z2 = (1/4)-(1/4)sin((5/2)PI-8a)
-------------------
*/

#include <stdio.h>
#include <math.h>
#include <time.h>

#define PI 3.141592

double calculation(double a, int zet);

double alpha = 0.0;
double result = 0.0;

int main()
{
    srand(time(NULL));  
   
    for(int i = 0; i < 5; i++){
        alpha = rand()%181;
        printf("alpha = %lf\r\n", alpha);
        for(int j = 0; j < 2; j++) {
            printf("z%d = %lf \r\n", j+1, calculation(alpha, j));
        }
        printf("\r\n");
    }
    return 0;
}

double calculation(double a, int zet){
    if(!zet){
        return (cos(a) + sin(a) + cos(3.0*a) + sin(3.0*a));
    } 
    else{
        return  ((2.0 * sqrt(2.0)) * cos(a) * sin ((PI/4.0) + (2.0*a)));
    }
}