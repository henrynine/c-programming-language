#include <stdio.h>
#define LISTSIZE 100000
#define SCOUNT 10000000
int old_binsearch(int x, int v[], int n);
int new_binsearch(int x, int v[], int n);

int main() {
  int i, sorted_list[LISTSIZE];
  for (i = 0; i < LISTSIZE; i++)
    sorted_list[i] = i;
  // old_binsearch, do 10000000 times, listsize 100000 takes 0.6 seconds
  /*for (i = 0; i < SCOUNT; i++)
    old_binsearch(LISTSIZE/2-1, sorted_list, LISTSIZE);*/
  // new_binsearch, do 10000000 times, listsize 100000 takes .06 seconds
  for (i = 0; i < SCOUNT; i++)
    new_binsearch(1, sorted_list, LISTSIZE); // -1 for worst case scenario
}

// binsearch: find x in sorted list v v[0] ... v[n-1]
int old_binsearch(int x, int v[], int n)
{
       int low, high, mid;
       low = 0;
       high = n - 1;
       while (low <= high) {
           mid = (low+high)/2;
           if (x < v[mid])
               high = mid + 1;
           else if (x  > v[mid])
               low = mid + 1;
           else    /* found match */
               return mid;
       }
       return -1;   /* no match */
}

// binsearch: find x in sorted list v v[0] ... v[n-1]
int new_binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n-1;
  while (low <= high && x != v[mid]) {
    mid = (low+high)/2;
    if (x < v[mid])
      high = mid + 1;
    else
      low = mid + 1;
  }
  if (x == v[mid])
    return mid;
  return -1; // no match
}
