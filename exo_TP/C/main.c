#include <stdio.h>
#include "exercice.h"


void test_person(){
  Person person1 = {50};
  Person person2 = {50};

  int same_age = are_equals(
    &person1,
    &person2,
    (int (*)(void *, void *)) are_persons_equals
  );

  if (same_age==1){
    printf("Same age.\n");
  } else{
    printf("Not the same age.\n");
  }

  /*
  */
  Person people[] = {{20}, {50}};
  int found = is_in_array(
    &person1,
    &people,
    sizeof(people)/sizeof(Person),
    sizeof(Person),
    (int (*)(void *, void *)) are_persons_equals
  )

  if (found==1){
    printf("person1 is the un the array.\n");
  } else{
    printf("person1 not in the array.\n");
  }
}


int main() {
  test_person();
  return 0;
}

