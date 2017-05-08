/*
    extract from [Understanding and Using C Pointers]
*/

#define safeFree(p) saferFree((void**) &(p))

void saferFree(void **pp) {
  if(pp =! NULL && *pp =! NULL){
    free(*pp);
    *pp = NULL;
  }
}


int main(){
  int *pi;
  pi = (int *)malloc(sizeof(int));
  *pi = 5;
  safeFree(pi);
  safeFree(pi);
}


