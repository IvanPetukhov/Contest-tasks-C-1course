  #include <stdio.h>
  #include <stdlib.h>

  int main(void)
  {
      int N, maximum, minimum, i, a;
      maximum = -1000000000;
      minimum = 1000000000;
      scanf("%d", &N);
      for (i=1; i<=N; i++)
      {
          scanf("%d", &a);
          if (a>maximum) maximum=a;
          if (a<minimum) minimum=a;
      }
      printf("%d\n", (maximum-minimum));
      return 0;
  }

