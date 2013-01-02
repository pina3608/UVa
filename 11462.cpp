#include "stdio.h"

#define MAX_AGE 100

int main(){

  int n;
  int qty[MAX_AGE];

  while (true){
    
    scanf("%d",&n);
    if ( n == 0) break;

    for (int i = 0; i < MAX_AGE; i++) qty[i] = 0;
    for (int i = 0; i < n; i++){

      int age;
      scanf("%d", &age);
      qty[age-1]++;
    }
    bool first = true;
    for (int i = 0; i < MAX_AGE; i++){
      for (int j = 0; j < qty[i]; j++){
        if(first){
          printf("%d", i+1);
          first = false;
        }
        else printf(" %d", i+1);
      }
    }
    printf("\n");
    
  }

  return 0;
}
