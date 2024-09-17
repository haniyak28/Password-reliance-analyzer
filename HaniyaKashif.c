#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hasLowercase(char x[]) {
  int i;
  for(i = 0; x[i] != '\0'; i++) {
    if (x[i]>='a' && x[i]<='z') {
      return 1;
    }
  }
  return 0;
}

int hasUppercase(char x[]) {
  int i;
  for(i = 0; x[i] != '\0'; i++) {
    if (x[i]>='A' && x[i]<='Z') {
      return 1;
    }
  }
  return 0;
}

int hasDigit(char x[]) {
  int i;
  for(i = 0; x[i] != '\0'; i++) {
    if (x[i]>='0' && x[i]<='9') {
      return 1;
    }
  }
  return 0;
}

int hasSpecialChar(char x[]) { //check if spaces should be read or not
  int i;
  for(i = 0; x[i] != '\0'; i++) {
    if (!isalnum(x[i])) {
      return 1;
    }
  }
  return 0;
}

int lengthCheck(char x[]) {
  if (strlen(x)>=12) {
    return 1;
  }
  return 0;
}

int evaluateStrength(char x[]) {
  int stren = 0;
  if (hasLowercase(x)) {
    stren++;
  }
  if (hasUppercase(x)) {
    stren++;
  }
  if (hasDigit(x)) {
    stren++;
  }
  if (hasSpecialChar(x)) {
    stren++;
  }
  if (lengthCheck(x)) {
    stren++;
  }
  return stren;
}


void printStrength(char pass[]) {
  if ((evaluateStrength(pass) <= 2) && (evaluateStrength(pass) >= 0)) {
    printf("Weak\n\n");
  } else if ((evaluateStrength(pass) >= 3) && (evaluateStrength(pass) <= 4)) {
    printf("Moderate\n\n");
  } else if (evaluateStrength(pass) >= 5) {
    printf("Strong\n\n");
  }
}


int main() {
  //main menu
  char pass[100];
  char opt[100];
  while (1) {
    printf("Password Relience Analyzer\n\t1. Test a new password\n\t2. View strength of the last tested password\n\t3. Exit\n");
    printf("Enter your choice: ");
    scanf("%s",opt);
    if (strcmp(opt,"1") == 0) {
      printf("Enter the password: ");
      scanf("%s",pass);
      if (strlen(pass)<8) {
        printf("Error: Password should be at least 8 characters long.\n\n");
      } else {
        printf("Password Strength: ");
        printStrength(pass);
      }
    } else if (strcmp(opt,"2") == 0) {
      if (pass[0] != '\0') {
        printf("Last tested password strength: ");
        printStrength(pass);
      }
    } else if (strcmp(opt,"3") == 0) {
      printf("Exiting...\n");
      break;
    } else {
      printf("error in input type, try again\n\n");
    }
  } 
  return 0;
}
