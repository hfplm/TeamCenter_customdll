#include"Header.h"
#define errCode (EMH_USAGE_error_base + 536)

int ugHandler(METHOD_message_t* msg, va_list args) {
	char* objType,* secObjType;
	tag_t sourcePrimary = va_arg(args, tag_t);
	tag_t sourceSecondary = va_arg(args, tag_t);
	int count, ifail;
	tag_t* secObj;
	int flag = 0;


	ifail= WSOM_ask_object_type2(sourceSecondary, &secObjType);
	if (tc_strcmp(secObjType, "UGPART") == 0)
	{
		ifail = GRM_list_secondary_objects_only(sourcePrimary, NULLTAG, &count, &secObj);
		for (int i = 0; i < count; i++) {
			WSOM_ask_object_type2(secObj[i], &objType);

			if (tc_strcmp(objType, "UGMASTER") == 0) {
				flag = 1;
				break;

			}
		}

		if (secObj)MEM_free(secObj);

		if (flag == 0) {

			EMH_store_error_s1(EMH_severity_error, errCode, "Can't attach UGPART since UGMASTER is not attached ! ");
			return errCode;
		}
	}
		return 0;

	//if (flag != 1) {
	

}