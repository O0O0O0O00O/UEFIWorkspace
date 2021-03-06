/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_E04894D6_290D_4171_A362_0ACFD939F3C8
#define _AUTOGENH_E04894D6_290D_4171_A362_0ACFD939F3C8

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern EFI_GUID gEfiSmmLockBoxCommunicationGuid;
extern EFI_GUID gEdkiiEndOfS3ResumeGuid;

// Protocols
extern EFI_GUID gEfiMmReadyToLockProtocolGuid;
extern EFI_GUID gEfiMmEndOfDxeProtocolGuid;
extern EFI_GUID gEfiMmSxDispatchProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

EFI_STATUS
EFIAPI
SmmLockBoxTraditionalConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

EFI_STATUS
EFIAPI
SmmLockBoxTraditionalDestructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );


#ifdef __cplusplus
}
#endif

#endif
