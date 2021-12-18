#include <stdio.h>

int main() {

   int j = 0;

   for (int a = 0; a < 5; a++) {
      for (int b = 0; b < 5; b++) {
         j++;
         if (j <= 10) {
            if (j % 3 == 0) {
               printf("★");
            }
            else 
               printf("%d", j);
            
         }
         if (j > 10 && j <= 20) {
            if (j % 3 == 1) {
               printf("★");
            }
            else
               printf("%d", j);
         }

         if (j > 20 && j <= 25) {
            if (j % 3 == 2) {
               printf("★");
            }
            else
               printf("%d", j);
               }
            
         }
      printf("\n");
   }
   return 0;
}
