#include "exercice.h"

int are_persons_equals(Person *p1, Person *p2){
  // return 1 if `age` is the same
  if ((*p1).age == (*p2).age){
    return 1;
  } else {
    return 0;
  }
}

int are_books_equals(Book *b1, Book *b2){
  // return 1 if `pages` is the same
  if ((*b1).pages == (*b2).pages){
    return 1;
  } else {
    return 0;
  }
  return 0;
}

int are_equals(void *obj1, void *obj2, int (*compare_fnc)(void*, void*)){
  return 0;
}

