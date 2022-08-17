#include"Header.h"
#define errCode (EMH_USAGE_error_base + 536)

int reviseHandler(METHOD_message_t* msg, va_list args) {
	char* value;
	tag_t sourceRev = va_arg(args, tag_t);

	AOM_UIF_ask_value(sourceRev, "fnd0InProcess", &value);
	if (tc_strcmp(value, "True") == 0) {
		printf("\n\n\n*********************************************\n");
		printf("*                                           *\n");
		printf("*\t Successfully Revised               *\n");
		printf("*                                           *\n");
		printf("*********************************************\n\n\n");

		return 0;
	}
	else {
		EMH_store_error_s1(EMH_severity_error, errCode, "The Revise operation can't be preformed unless it is in workflow process");
		return errCode;
	}
}