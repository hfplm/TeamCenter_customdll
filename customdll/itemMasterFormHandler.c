#include"Header.h"
#define errCode (EMH_USAGE_error_base + 536)

int itemMasterFormHandler(METHOD_message_t* msg, va_list args) {
	char* value;
	tag_t sourceForm = va_arg(args, tag_t);

	AOM_UIF_ask_value(sourceForm, "user_data_1", &value);
	if (tc_strlen(value)<=20) {
		printf("\n\n\n*********************************************\n");
		printf("*                                           *\n");
		printf("*\t Successfully created                *\n");
		printf("*                                           *\n");
		printf("*********************************************\n\n\n");

		return 0;
	}
	else {
		EMH_store_error_s1(EMH_severity_error, errCode, "The user data 1 string length must be less than or equal to 20");
		return errCode;
	}
}