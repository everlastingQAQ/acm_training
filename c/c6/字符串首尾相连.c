#include <stdio.h>
int main() {
    char str1[101],str2[101];
    int i,j;

    gets(str1);
    gets(str2);
  // Here is your code
    i = 0;
    while (str1[i] != '\0' && str1[i] != '\n') {
        i++;
    }
    str1[i] = '\0'; 
    
    j = 0;
	while (str2[j] != '\0' && str2[j] != '\n') {
        j++;
    }
    str2[j] = '\0';
    
	for (int k = 0; k < j; k++) {
        str1[i] = str2[k];
        i++;
    }
    str1[i] = '\0';

  puts(str1);
  return 0;
}
