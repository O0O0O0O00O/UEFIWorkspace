/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_13AC6DD0_73D0_11D4_B06B_00AA00BD6DE7
#define _AUTOGENH_13AC6DD0_73D0_11D4_B06B_00AA00BD6DE7

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x13AC6DD0, 0x73D0, 0x11D4, {0xB0, 0x6B, 0x00, 0xAA, 0x00, 0xBD, 0x6D, 0xE7}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x587CE499, 0x6CBE, 0x43cd, {0x94, 0xE2, 0x18, 0x62, 0x18, 0x56, 0x94, 0x78}}

// Guids
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiDebugSupportProtocolGuid;
extern EFI_GUID gEfiEbcProtocolGuid;
extern EFI_GUID gEdkiiPeCoffImageEmulatorProtocolGuid;
extern EFI_GUID gEfiEbcVmTestProtocolGuid;
extern EFI_GUID gEfiEbcSimpleDebuggerProtocolGuid;
extern EFI_GUID gEfiLoadedImageProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
InitializeEbcDriver (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
