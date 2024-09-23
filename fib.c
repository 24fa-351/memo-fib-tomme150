#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
int memo[MAX];

void init_memo() {
   for (int i = 0; i < MAX; i++) {
      memo[i] = -1;
   }
}

unsigned long long int recursive(unsigned long long int n) {
   if (n <= 1) {
      return n;
   } else {
      return recursive(n - 1) + recursive(n - 2);   
   }
}

unsigned long long int recur_memo(unsigned long long int n) {
   if (n <= 1) {
      return n;
   }

   if (memo[n] != -1) {
      return memo[n];
   }

   memo[n] = recursive(n);

   return memo[n];
}

unsigned long long int iterative(unsigned long long int n) {
    if (n <= 1) {
      return n;
    }
   
    unsigned long long int a = 0, b = 1, fib = 0;
    for (unsigned long long int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
      }
    return memo[fib];
    return fib;
}

unsigned long long int iter_memo(unsigned long long int n) {
   if (n <= 1){
      return n;
   }

   int *memo = (int *)malloc((n + 1) * sizeof(int));

   memo[0] = 0;
   memo[1] = 1;

   for (int i = 2; i <= n; i++) {
      memo[i] = memo[i - 1] + memo[i - 2];
   }

   int result = memo[n];

   free(memo);

   return result;
}

int main(unsigned long long int argc, char *argv[]) {
   if (argc != 3) {
      printf("Please type in an integer and method(i or r)\n", argv[0]);
      return 1;
   }
   
   unsigned long long int number = atoi(argv[1]);
   init_memo();
   char *method = argv[2];
   
   // if (number == 1) {
   //   number = number - 1;
   // }

   // Debugging
   // printf("%d\n", number);
   // printf("%s\n", method);
      
   unsigned long long int results;

   if (strcmp(method, "r")  == 0) {
      // results = recursive(number);
      results = recur_memo(number);
   } else if (strcmp(method, "i")  == 0) {
      // results = iterative(number);
      results = iter_memo(number);
   } else {
      printf("Use 'r' for recursive or 'i' for iterative.\n");
      return 1;
   }

   printf("%d\n", results);

   return 0;
}
