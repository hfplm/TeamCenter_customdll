#include"Header.h"
#define errCode (EMH_USAGE_error_base + 536)

int bomHandler(METHOD_message_t* msg, va_list args) {
	tag_t currRole;
	char* role;
	tag_t sourceBOM = va_arg(args, tag_t);

	SA_ask_current_role(&currRole);

	SA_ask_role_name2(currRole, &role);

	if (tc_strcmp(role, "engineer") == 0) {
		printf("\n\n\n*********************************************\n");
		printf("*                                           *\n");
		printf("*\t Successfully created BOM                *\n");
		printf("*                                           *\n");
		printf("*********************************************\n\n\n");

		return 0;
	}
	else {
		EMH_store_error_s1(EMH_severity_error, errCode, "Can't create BOM Line unless role is engineer");
		return errCode;
	}
}