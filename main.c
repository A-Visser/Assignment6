#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//prints out all values in array
int printAll(int *a, int len){
  int i;
  for(i = 0; i < len/sizeof(*a); i++){
    printf("%d\n",a[i]);
  }
  return 0;
}
int findAverage(int *a, int len){
  int i;
  unsigned long sum = 0;
  for(i = 0; i < len/sizeof(*a); i++){
    sum += a[i];
  }
  return sum/len*sizeof(*a);
}
int copy(int *a, int *b, int len){
  int i;
  for(i = 0; i < len/sizeof(*a); i++){
    b[i] = a[i];
  }
  return 0;
}
int main(){
  int a[10], b[10],i;
  srand(time(NULL));
  for(i = 0; i < 10; i++){
    a[i]= rand();
  }
  for(i = 0; i < 10; i++){
    b[i]= rand();
  }
  int *ap = a;
  int *bp = b;
  printf("First array:\n");
  printAll(ap, sizeof(a));
  printf("Average value: %d \n", findAverage(ap, sizeof(a)));
  printf("Second array: \n");
  printAll(bp, sizeof(b));
  printf("Average value: %d \n", findAverage(bp, sizeof(b)));
  printf("Copy first array to second\n");
  copy(ap, bp, sizeof(a));
  printf("Second array: \n");
  printAll(bp, sizeof(b));
  return 0;
}
