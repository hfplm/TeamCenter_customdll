#include"Header.h"

extern DLLAPI int libhonda_register_callbacks() {

	CUSTOM_register_exit("libhonda", "USER_init_module", (CUSTOM_EXIT_ftn_t)hondaFunc1);
	CUSTOM_register_exit("libhonda", "USER_exit_module", (CUSTOM_EXIT_ftn_t)hondaFunc2);
	return 0;
}

extern DLLAPI int hondaFunc1(int* decision, va_list args) {
	METHOD_id_t revMethodID;
	METHOD_id_t reviseMethodID;
	METHOD_id_t itemMethodID;
	*decision = ALL_CUSTOMIZATIONS;
	printf("\n\n\n*********************************************\n");
	printf("*                                           *\n");
	printf("*\t Welcome to honda env               *\n");
	printf("*                                           *\n");
	printf("*********************************************\n\n\n");

	METHOD_find_method("ItemRevision", "ITEM_copy_rev", &reviseMethodID);
	METHOD_add_pre_condition(reviseMethodID, (METHOD_function_t)itemHandler, NULL);
	
	// METHOD_find_method("Item", "ITEM_create", &itemMethodID);
	// METHOD_add_pre_condition(itemMethodID, (METHOD_function_t)itemHandler, NULL);

	METHOD_find_method("ItemRevision", "ITEM_create_rev", &revMethodID);
	METHOD_add_pre_condition(revMethodID, (METHOD_function_t)itemHandler, NULL);

	return 0;
}

extern DLLAPI int hondaFunc2(int* decision, va_list args) {
	*decision = ALL_CUSTOMIZATIONS;
	printf("\n\n\n*********************************************\n");
	printf("*                                           *\n");
	printf("*\t Thanks for visiting honda env      *\n");
	printf("*                                           *\n");
	printf("*********************************************\n\n\n");
	return 0;
}