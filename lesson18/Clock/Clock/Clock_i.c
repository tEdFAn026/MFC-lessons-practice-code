

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon May 06 14:40:12 2019
 */
/* Compiler settings for Clock.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
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
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_ClockLib,0x4FD2DA21,0x84C2,0x4AC7,0xBE,0xD4,0x97,0x57,0x80,0x06,0xCB,0x3B);


MIDL_DEFINE_GUID(IID, DIID__DClock,0xF78DF301,0x071B,0x4531,0xA5,0xF3,0xDC,0x42,0xDF,0xDF,0xE8,0x98);


MIDL_DEFINE_GUID(IID, DIID__DClockEvents,0x600C57C4,0xE86C,0x4D40,0x93,0x44,0x76,0x6C,0x85,0x28,0x17,0xDC);


MIDL_DEFINE_GUID(CLSID, CLSID_Clock,0xED3DB106,0xF475,0x49E8,0xB0,0x1D,0x0D,0xC5,0x04,0x70,0xAD,0x45);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



