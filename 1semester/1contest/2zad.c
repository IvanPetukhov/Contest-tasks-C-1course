#include <stdio.h>
  #include <stdlib.h>

  int main(void)
  {
      int N, kol, i;
      long long a, maximum;
      scanf("%d", &N);
      scanf("%lld", &a);
      maximum = a;
      kol = 1;
      for (i = 2; i <= N; i++)
      {
          scanf("%lld", &a);
          if (a > maximum)
          {
            maximum = a;
            kol = 0;
          }
          if (a == maximum)
          {
              ++kol;
          }
      }
      printf("%d\n", kol);
      return 0;
  }

