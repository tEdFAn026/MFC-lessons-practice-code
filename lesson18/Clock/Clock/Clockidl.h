

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __Clockidl_h__
#define __Clockidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DClock_FWD_DEFINED__
#define ___DClock_FWD_DEFINED__
typedef interface _DClock _DClock;

#endif 	/* ___DClock_FWD_DEFINED__ */


#ifndef ___DClockEvents_FWD_DEFINED__
#define ___DClockEvents_FWD_DEFINED__
typedef interface _DClockEvents _DClockEvents;

#endif 	/* ___DClockEvents_FWD_DEFINED__ */


#ifndef __Clock_FWD_DEFINED__
#define __Clock_FWD_DEFINED__

#ifdef __cplusplus
typedef class Clock Clock;
#else
typedef struct Clock Clock;
#endif /* __cplusplus */

#endif 	/* __Clock_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_Clock_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_Clock_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Clock_0000_0000_v0_0_s_ifspec;


#ifndef __ClockLib_LIBRARY_DEFINED__
#define __ClockLib_LIBRARY_DEFINED__

/* library ClockLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_ClockLib;

#ifndef ___DClock_DISPINTERFACE_DEFINED__
#define ___DClock_DISPINTERFACE_DEFINED__

/* dispinterface _DClock */
/* [uuid] */ 


EXTERN_C const IID DIID__DClock;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F78DF301-071B-4531-A5F3-DC42DFDFE898")
    _DClock : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DClockVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DClock * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DClock * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DClock * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DClock * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DClock * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DClock * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DClock * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DClockVtbl;

    interface _DClock
    {
        CONST_VTBL struct _DClockVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DClock_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DClock_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DClock_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DClock_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DClock_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DClock_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DClock_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DClock_DISPINTERFACE_DEFINED__ */


#ifndef ___DClockEvents_DISPINTERFACE_DEFINED__
#define ___DClockEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DClockEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DClockEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("600C57C4-E86C-4D40-9344-766C852817DC")
    _DClockEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DClockEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DClockEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DClockEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DClockEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DClockEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DClockEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DClockEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DClockEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DClockEventsVtbl;

    interface _DClockEvents
    {
        CONST_VTBL struct _DClockEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DClockEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DClockEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DClockEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DClockEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DClockEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DClockEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DClockEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DClockEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Clock;

#ifdef __cplusplus

class DECLSPEC_UUID("ED3DB106-F475-49E8-B01D-0DC50470AD45")
Clock;
#endif
#endif /* __ClockLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


