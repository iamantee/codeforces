/* *
 * author     : antee
 * date       : 2016-05-19 22:46
 * description: This program is a solution for the "Summer Camp" problem on codeforces.
 *              To access the problem, please click this link: http://codeforces.com/problemset/problem/672/A
 * */

#define DIGIT_COUNT_OF_TENS 2
#define DIGIT_COUNT_OF_HUNDREDS 3
#define TEN 10
#define HUNDRED 100
#define BOUNDARY_OF_TENS 10
#define BOUNDARY_OF_HUNDREDS (9 * 10 * 2 + 10)

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
  int position = atoi(argv[1]);
  int number = 0;
  int digit = 0;
  int digit_position = 0;
  int boundary_of_tens = BOUNDARY_OF_TENS;
  int boundary_of_hundreds = BOUNDARY_OF_HUNDREDS;

  if(argc <= 1 || argc > 2){
    printf("Position inputted incorrectly.");
    return -1;
  }

  if(position < boundary_of_tens){
    digit = position;
  }
  else if(position >= BOUNDARY_OF_TENS && position < BOUNDARY_OF_HUNDREDS){
    number = ((position - BOUNDARY_OF_TENS) / DIGIT_COUNT_OF_TENS) + TEN;
    digit_position = (position - BOUNDARY_OF_TENS) % DIGIT_COUNT_OF_TENS;
    if(digit_position == 0) digit = number / TEN;
    else if(digit_position == 1) digit = number % TEN;
  }
  else if(position >= BOUNDARY_OF_HUNDREDS){
    number = ((position - BOUNDARY_OF_HUNDREDS) / DIGIT_COUNT_OF_HUNDREDS) + HUNDRED;
    digit_position = (position - BOUNDARY_OF_HUNDREDS) % DIGIT_COUNT_OF_HUNDREDS;
    if(digit_position == 0) digit = number / HUNDRED;
    else if(digit_position == 1){
      digit = (number % HUNDRED) / TEN;
    }
    else if(digit_position == 2){
      digit = (number % HUNDRED) % TEN;
    }
  }

  printf("\n%d\n", digit);

  return 0;
}
