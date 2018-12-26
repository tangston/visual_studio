

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for SimpleChat.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __SimpleChat_h_h__
#define __SimpleChat_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISimpleChat_FWD_DEFINED__
#define __ISimpleChat_FWD_DEFINED__
typedef interface ISimpleChat ISimpleChat;

#endif 	/* __ISimpleChat_FWD_DEFINED__ */


#ifndef __SimpleChat_FWD_DEFINED__
#define __SimpleChat_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimpleChat SimpleChat;
#else
typedef struct SimpleChat SimpleChat;
#endif /* __cplusplus */

#endif 	/* __SimpleChat_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __SimpleChat_LIBRARY_DEFINED__
#define __SimpleChat_LIBRARY_DEFINED__

/* library SimpleChat */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_SimpleChat;

#ifndef __ISimpleChat_DISPINTERFACE_DEFINED__
#define __ISimpleChat_DISPINTERFACE_DEFINED__

/* dispinterface ISimpleChat */
/* [uuid] */ 


EXTERN_C const IID DIID_ISimpleChat;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("05462393-207b-4510-a9e1-ebecd5bcb3ec")
    ISimpleChat : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISimpleChatVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimpleChat * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimpleChat * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimpleChat * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISimpleChat * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISimpleChat * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISimpleChat * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISimpleChat * This,
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
    } ISimpleChatVtbl;

    interface ISimpleChat
    {
        CONST_VTBL struct ISimpleChatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleChat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimpleChat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimpleChat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimpleChat_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISimpleChat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISimpleChat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISimpleChat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISimpleChat_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SimpleChat;

#ifdef __cplusplus

class DECLSPEC_UUID("ac8f8dfa-7879-49cc-959a-65dbdd09e435")
SimpleChat;
#endif
#endif /* __SimpleChat_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


