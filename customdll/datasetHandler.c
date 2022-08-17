#include"Header.h"
#define errCode (EMH_USAGE_error_base + 536)

int deleteHandler(METHOD_message_t* msg, va_list args) {
	char* className;
	tag_t sourceRev = va_arg(args, tag_t);
	int count;
	tag_t classID;
	tag_t* secObj;
	int flag = 0;

	GRM_list_secondary_objects_only(sourceRev, NULLTAG, &count, &secObj);
	for (int i = 0; i < count; i++) {
		// WSOM_ask_object_type2(secObj[i])
		POM_class_of_instance(secObj[i], &classID);
		POM_name_of_class(classID, &className);

		if (tc_strcmp(className, "Dataset") != 0) {
		
			printf("\n\n\n*********************************************\n");
			printf("*                                           *\n");
			printf("*\t Successfully deleted                 *\n");
			printf("*                                           *\n");
			printf("*********************************************\n\n\n");

			return 0;

		}
		else {
			EMH_store_error_s1(EMH_severity_error, errCode, "Can't delete Revision due to dataset attached");
			return errCode;
		}

	}
	//if (flag != 1) {
	

}