//#c++
#ifndef c_plus_plus
#include <stdio.h>
#include <string.h>
#else
#include <iostream>
//!Exception
class Exception
{
    //*premeters
    protected:
    std::string Err , Message;
    public:
    /*print*/
    void print()
    {
        std::cerr<< Err<<"("<<Message<<")";
    }
    /*raise*/
    void raise()
    {
        print(); exit(1);
    }
};
#define creatErrorClass(clsName,clsStrName) \
class clsName :Exception {Err =clsStrName;public:  clsName(char* message){ Message = clsStrName;}};
#endif
//#c
//*typedefs
typedef char* str;
typedef str* Error;
//*Error var
Error* allErrors;
//*Error
Error notError = {"notError","Error "};
//*enum
const int message = 1 ,error = 0;
//*detMessage
Error setMessage(Error __error,str __message){__error[message]=__message;return __error;}
Error setMessage(Error *__error,str __message){*__error = setMessage(__error,__message);}
//*exit
int exit(Error Err);
//*print
int print(Error __error)
{
    if (sizeof(__error)/sizeof(Error)!=2){exit(__error);}
    printf("%s(%s)",__error[error],__error[message]);
    return 0;
}
//*isEqual
int isEqual(str __a,str __b)
{
    if(sizeof(__a)!=sizeof(__b)){return 0;}
    for (size_t i = 0; i < sizeof(__a)/sizeof(str); i++)
    {
        if(__a[i]!=__b[i]){return 0;}
    }
    return 1;
}
//*isError
int isError(){return sizeof(allErrors)==0;}
int isError(Error __error)
{
    for (size_t i = 0; i < sizeof(allErrors)/sizeof(Error); i++)
    {
        if(isEqual(allErrors[i][error],__error)&& isEqual(allErrors[i][message],__error[message])){return 1;}
    }
    return 0;
}
int exit(Error Err){int returing; printf(Err);exit(1);}
//*raise 
int raise (Error Err) { allErrors[(sizeof(allErrors)/sizeof(Error))-1] = Err;}
int main(str *const,int)
{
    return 0;
}