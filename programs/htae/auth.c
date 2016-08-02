#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Note:
  Care should be taken about providing the input for expoliting the buffer overflows.
  If you endup providing a very large input, then it might corrupt the entire stack and hence cause segfault
  instead of getting the required overflow result. */

/* exploit inputs : 
	-> 11111111111111111111111111111111111111: results in access granted and segfault.
	-> aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa : results in access granted and no segfault :-) . 
	-> aaaaaaaaaaaaaaaaaaaaaaaaaaaaa : min length for safe access granted without segfault.
*/
int check_authentication(char *password) {
	int auth_flag = 0;
	char password_buffer[16];
	fprintf(stderr, "pass = %s\n", password);
	strcpy(password_buffer, password);
	if(strcmp(password_buffer, "brillig") == 0)
		auth_flag = 1;
	if(strcmp(password_buffer, "outgrabe") == 0)
		auth_flag = 1;
	return auth_flag;
}
int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Usage: %s <password>\n", argv[0]);
		exit(0);
	}
	if(check_authentication(argv[1])) {
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("Access Granted.\n");
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	} else {
		printf("\nAccess Denied.\n");
	}
}
