/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_F74D20EE_37E7_48FC_97F7_9B1047749C69
#define _AUTOGENH_F74D20EE_37E7_48FC_97F7_9B1047749C69

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xF74D20EE, 0x37E7, 0x48FC, {0x97, 0xF7, 0x9B, 0x10, 0x47, 0x74, 0x9C, 0x69}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x587CE499, 0x6CBE, 0x43cd, {0x94, 0xE2, 0x18, 0x62, 0x18, 0x56, 0x94, 0x78}}

// Guids
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiHiiDatabaseProtocolGuid;
extern EFI_GUID gEfiHiiImageExProtocolGuid;
extern EFI_GUID gEfiHiiPackageListProtocolGuid;
extern EFI_GUID gEdkiiPlatformLogoProtocolGuid;
extern EFI_GUID gEfiLoadedImageProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
InitializeLogo (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );



#include "LogoDxeImgDefs.h"


#ifdef __cplusplus
}
#endif

#endif
