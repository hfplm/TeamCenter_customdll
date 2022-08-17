#include"Header.h"
#define errCode (EMH_USAGE_error_base + 321)

int saveAsHandler(METHOD_message_t* msg, va_list args) {
	char* value;
	tag_t currRole;
	char* role;
	tag_t sourceRev = va_arg(args, tag_t);

	SA_ask_current_role(&currRole); 
	SA_ask_role_name2(currRole, &role);

	AOM_UIF_ask_value(sourceRev, "b2_isActive", &value);
	if ((tc_strcmp(role, "engineer") == 0) && (tc_strcmp(value, "enable") == 0)) {
		printf("\n\n\n*********************************************\n");
		printf("*                                           *\n");
		printf("*\t Successfully created Item From Revision *\n");
		printf("*                                           *\n");
		printf("*********************************************\n\n\n");

		return 0;
	}
	else {
		EMH_store_error_s1(EMH_severity_error, errCode, "The save as operation can't be preformed ");
		return errCode;
	}
}