

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 08:44:07 2038
 */
 /* Compiler settings for MyATLProject.idl:
     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628
     protocol : all , ms_ext, c_ext, robust
     error checks: allocation ref bounds_check enum stub_data
     VC __declspec() decoration level:
          __declspec(uuid()), __declspec(selectany), __declspec(novtable)
          DECLSPEC_UUID(), MIDL_INTERFACE()
 */
 /* @@MIDL_FILE_HEADING(  ) */



#ifdef __cplusplus
extern "C" {
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

    typedef struct _IID
    {
        unsigned long x;
        unsigned short s1;
        unsigned short s2;
        unsigned char  c[8];
    } IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
    typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

    MIDL_DEFINE_GUID(IID, LIBID_MyATLProjectLib, 0x6A3A67DD, 0x1625, 0x4637, 0xB7, 0xDF, 0x8E, 0x55, 0x71, 0x9F, 0x88, 0xCC);


    MIDL_DEFINE_GUID(IID, IID_IMyComObject, 0x06F0CFB7, 0x7715, 0x4886, 0xB8, 0xF7, 0x0B, 0x2F, 0xB4, 0xCF, 0x0C, 0x7A);


    MIDL_DEFINE_GUID(CLSID, CLSID_CMyComObject, 0xE44E93DD, 0xD430, 0x42D8, 0x83, 0x1A, 0x89, 0x2B, 0x63, 0x2D, 0x31, 0x15);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



