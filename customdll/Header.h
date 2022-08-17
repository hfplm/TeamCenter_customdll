#include<stdio.h>
#include<conio.h>
#include<tccore/custom.h>
#include<tccore/method.h>
#include<tccore/aom.h>
#include<tccore/aom_prop.h>
#include<fclasses/tc_string.h>
#include<tc/emh.h>
#include<sa/role.h>
#include<tccore/item.h>
#include<tccore/grm.h>
#include<pom/pom/pom.h>
#include<tccore/workspaceobject.h>



#define DLLAPI __declspec(dllexport)

extern DLLAPI int libhonda_register_callbacks();
extern DLLAPI int hondaFunc1(int* decision, va_list args);
extern DLLAPI int hondaFunc2(int* decision, va_list args);
int preConditionHandler(METHOD_message_t* msg, va_list args);
int saveAsHandler(METHOD_message_t* msg, va_list args);
int reviseHandler(METHOD_message_t* msg, va_list args);
int itemMasterFormHandler(METHOD_message_t* msg, va_list args);
int bomHandler(METHOD_message_t* msg, va_list args);
int deleteHandler(METHOD_message_t* msg, va_list args);
int checkoutHandler(METHOD_message_t* msg, va_list args);
int ugHandler(METHOD_message_t* msg, va_list args);
int itemHandler(METHOD_message_t* msg, va_list args);