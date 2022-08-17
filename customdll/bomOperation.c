#include"Header.h"

extern DLLAPI int libhonda_register_callbacks() {

	CUSTOM_register_exit("libhonda", "USER_init_module", (CUSTOM_EXIT_ftn_t)hondaFunc1);
	CUSTOM_register_exit("libhonda", "USER_exit_module", (CUSTOM_EXIT_ftn_t)hondaFunc2);
	return 0;
}

extern DLLAPI int hondaFunc1(int* decision, va_list args) {
	METHOD_id_t bomMethodID;
	*decision = ALL_CUSTOMIZATIONS;
	printf("\n\n\n*********************************************\n");
	printf("*                                           *\n");
	printf("*\t Welcome to honda env               *\n");
	printf("*                                           *\n");
	printf("*********************************************\n\n\n");

	METHOD_find_method("PSBOMViewRevision", "PS_bvr_create_occs", &bomMethodID);

	METHOD_add_pre_condition(bomMethodID, (METHOD_function_t)bomHandler, NULL);

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