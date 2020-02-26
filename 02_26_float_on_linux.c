#include <stdio.h>
#include <math.h>

void main() {

  float f_pi = acos(-1.0);
  double d_pi = acos(-1.0);

  printf("%f\n",f_pi);
  printf("%lf\n",d_pi);

  printf("%.20f\n",f_pi);
  printf("%.20lf\n",d_pi);  

  f_pi = f_pi * 7.0;
  d_pi = d_pi * 7.0;

  f_pi = f_pi * (1.0 / 7.0);
  d_pi = d_pi * (1.0 / 7.0);

  printf("%.20f\n",f_pi);
  printf("%.20lf\n",d_pi);
  int i;
  for (i = 2; i < 20; i++) {
    f_pi = f_pi * (float)i;
    d_pi = d_pi * (double)i;
  }
  for (i = 2; i < 20; i++) {
    f_pi = f_pi * (1.0 / (float)i);
    d_pi = d_pi * (1.0 / (double)i);
  }
printf("%.20f\n",f_pi);
printf("%.20lf\n",d_pi);

return;

}

/*
On a 64bit linux system this program produces the following:
[root@pilgrim ~]# gcc 02_26.c
[root@pilgrim ~]# ./a.out
3.141593
3.141593
3.14159274101257324219
3.14159265358979311600
3.14159274101257324219
3.14159265358979311600
3.14159297943115234375
3.14159265358979267191
[root@pilgrim ~]#

*/
