#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <unistd.h>

/* expected hook */
PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return PAM_SUCCESS;
}

/* expected hook, this is where custom stuff happens */
PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {
  const char* username;
  pam_get_user(pamh, &username, NULL);
  system("echo Smile \\(or press ctrl-c for next authentication method\\)");
  char command[1024];
  strcpy(command, "/usr/local/CVLock/checkdynamic.py ");
  strcat(command, username);
  strcat(command, " &>>/dev/null");
  if (!system(command)) return PAM_SUCCESS;
  else return PAM_AUTH_ERR;
}
