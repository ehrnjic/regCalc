#include <stdio.h>

unsigned int regStat = 0;

unsigned int regCalc(int cmnd) {
  if(cmnd >= 1 & cmnd <= 16) {
    if (!(regStat & 1<<(cmnd - 1))) {regStat += 1<<(cmnd - 1);}
  } 
  else if (cmnd <= -1 && cmnd >= -16) {
    if (regStat & 1<<((cmnd * -1) - 1)) {regStat -= 1<<((cmnd * -1) - 1);}
  }
  else {
    regStat = 0;
  }
  return regStat;
}

void regStat2Bin(int dec){
  int regStatBin[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  printf("Bin regStat is now: ");
  for (int i = 15; i >= 0; i--) {
    regStatBin[i] = (dec >> i) & 1;
    printf("%i", regStatBin[i]);
  }
  printf("\n");
}

int main(){
  int in=0;
  unsigned int res;
  do {
    printf("Enter regCmnd [-16..16, 99-Exit]: ");
    scanf("%i", &in);
    if(in>=-16 && in<=16){
      res = regCalc(in);
      printf("Dec regStat now is: %u\n", res);
      regStat2Bin(res);
    }
  } while (in!=99);
}