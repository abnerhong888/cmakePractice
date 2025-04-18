#ifndef __DYNAMICLIB_H__
#define __DYNAMICLIB_H__


#define START_NAMESPACE namespace dynamiclib {  
#define END_NAMESPACE }

#if defined(_WIN32) || defined(_WIN64)
#   define __STDCALL__ __stdcall
#elif defined(__linux__)
#   define __STDCALL__ 
#endif


#if defined(_WIN32) || defined(_WIN64)
#   define __EXPORT__ __declspec(dllexport)
#   define __IMPORT__ __declspec(dllimport)
#elif defined(__linux__)
#   define __EXPORT__ __attribute__((visibility("default")))
#   define __IMPORT__ 
#endif


#if defined(DLLEXPORT)
#   define API extern "C" __EXPORT__
#else
#   define API extern "C" __IMPORT__
#endif


START_NAMESPACE

API char* __STDCALL__ getString();


END_NAMESPACE

#undef __EXPORT__
#undef __IMPORT__




#ifdef __DLL_EXPORT_USING__

#define __NAME__ "dynamic"

#if defined(_WIN32) || defined(_WIN64)
#   define __LIB_EXTENSION__ ".dll"
#elif defined(__linux__)
#   define __LIB_EXTENSION__ ".so"
#endif

#if defined(_MSC_VER)
#include "windows.h"
#define FPTR(__name) FPTR##__name
#define VAR_FPTR(__name) f##__name
#define HANDLE_DEF HMODULE handle = nullptr;
#define LIBRARYLOAD(__path) handle = LoadLibrary(__path);
#define LIBRARYFREE FreeLibrary(handle); handle = nullptr;
#define SET_PTR_VAR(__name) FPTR(__name) VAR_FPTR(__name) = nullptr;
#define GET_PTR(__name) (FPTR(__name))GetProcAddress(handle, #__name);
#define SET_ADDRESS(__name) VAR_FPTR(__name) = GET_PTR(__name);

#if defined(DEBUG)
#define LIBNAME __NAME__ "d" __LIB_EXTENSION__ 
#else
#define LIBNAME __NAME__ __LIB_EXTENSION__ 
#endif

#elif defined(__GNUC__)
#include <dlfcn.h>

#define FPTR(__name) FPTR##__name
#define VAR_FPTR(__name) f##__name
#define HANDLE_DEF void* handle = nullptr;
#define LIBRARYLOAD(__path) handle = dlopen(__path, RTLD_LAZY);
#define LIBRARYFREE dlclose(handle); handle = nullptr;
#define SET_PTR_VAR(__name) FPTR(__name) VAR_FPTR(__name) = nullptr;
#define GET_PTR(__name) (FPTR(__name))dlsym(handle, #__name);
#define SET_ADDRESS(__name) VAR_FPTR(__name) = GET_PTR(__name);

#if defined(DEBUG)
#define LIBNAME "lib" __NAME__ "d" __LIB_EXTENSION__ 
#else
#define LIBNAME "lib" __NAME__ __LIB_EXTENSION__ 
#endif

#endif


START_NAMESPACE

typedef char* (__STDCALL__ *FPTR(getString) )();


class DLLEXPORT{
public:
    DLLEXPORT(){
        LIBRARYLOAD(LIBNAME);
        SET_ADDRESS(getString);
    }
    ~DLLEXPORT(){
        LIBRARYFREE
    }

    SET_PTR_VAR(getString);

private:
    HANDLE_DEF
};

END_NAMESPACE

#undef __NAME__
#undef FPTR
#undef VAR_FPTR
#undef HANDLE_DEF 
#undef LIBRARYFREE
#undef LIBRARYLOAD
#undef SET_PTR_VAR
#undef GET_PTR
#undef SET_ADDRESS
#undef __LIB_EXTENSION__

#endif // __DLL_EXPORT_USING__



#endif // ifdef -__DYNAMICLIB_H__
