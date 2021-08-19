#include <stdio.h>
#include<time.h>
#include <stdlib.h>

#include "types.h"

void swap (uint_32*x , uint_32*y)
{
  uint_32 temp = *x;
  *x = *y;
  *y = temp;
}

void sort(uint_32* arr , uint_8 arr_size)       //selection sort
{
  static uint_8 min = 0;
  static uint_8 count = 0;

  min = count;

  for(int i = count+1 ;i < arr_size ; i++){     //detect minimum in unsorted
    if (arr[i] < arr[min]){
      min = i;
    }
  }
  swap(&arr[min],&arr[count]);              //swap real minimum with first unsorted
  if(count<arr_size)
  {
    count++;                              //repeat for unsorted only
    sort(arr,arr_size);
  }


}

uint_8 binarySearch (uint_32* arr ,uint_8 arr_size , uint_32 number)
{
  sort(arr,arr_size);

  uint_8 start = 0;
  uint_8 end = arr_size-1;
  uint_8 mid = (start + end) /2;

  if (arr[mid]<number)  {
    while (mid < end)
    {
      mid++;
      if(arr[mid] == number){
        return mid;
      }

    }
  }
  else if (arr[mid] > number){
    while (mid > start)
    {
      mid--;
      if(arr[mid] == number)
        return mid;
    }
  }
  else
    return mid;


  return -1;

}
int main()
{
  srand(time(0));

  uint_32 arr[5];
  uint_8 x = rand()%5;          //search for random variable

  for (int i = 0 ; i<5 ; i++)     //generate random array
  {
    arr[i]= rand()%8;
  }

  printf( "Searching for %d ...\n",x);
  x = binarySearch(arr,5,x);

  // Print Sorted array for testing
  for (int i =0;i<5 ; i++)
  {
    printf("%d\t",arr[i]);
  }

  if(x != 255)
  {
    printf("\nFound at index %d",x);
  }
  else
  {
    printf("\nNot Found!");
  }



  return 0;
}
