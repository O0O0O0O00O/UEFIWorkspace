/** @file
  Raw IP4 transmit application

  Copyright (c) 2011-2012, Intel Corporation. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "RawIp4Tx.h"

UINT8 mBuffer[1024];

/**
  Transmit raw IP4 packets to the remote system.

  @param [in] ArgC        Argument count
  @param [in] ArgV        Argument value array

  @retval 0               Successfully operation
 **/

int
RawIp4Tx (
  IN int ArgC,
  IN char **ArgV
  )
{
  UINT32 BytesSent;
  ssize_t BytesTransmitted;
  struct sockaddr_in LocalPort;
  UINT32 RemoteAddress[4];
  struct sockaddr_in RemotePort;
  int RetVal;
  UINT32 TotalSent;
  SOCKET s;

  //
  //  Create the socket
  //
  printf("1\n");
  s = socket ( AF_INET, SOCK_RAW, RAW_PROTOCOL );
  printf("2\n");
  if ( -1 == s ) {
    RetVal = GET_ERRNO;
    printf ( "ERROR - socket error, errno: %d\r\n", RetVal );
  }
  else {
    //
    //  Use for/break; instead of goto
    //
    printf("3\n");
    for ( ; ; ) {
      //
      //  Validate the arguments
      //
      if (( 2 > ArgC )
        || ( 4 != sscanf ( ArgV[1],
                           "%d.%d.%d.%d",
                           &RemoteAddress[0],
                           &RemoteAddress[1],
                           &RemoteAddress[2],
                           &RemoteAddress[3]))
          || ( 224 < RemoteAddress[0])
          || ( 255 < RemoteAddress[1])
          || ( 255 < RemoteAddress[2])
          || ( 255 < RemoteAddress[3])
          || (( 0 == RemoteAddress[0])
              && ( 0 == RemoteAddress[1])
              && ( 0 == RemoteAddress[2])
              && ( 0 == RemoteAddress[3]))) {
        printf ( "%s  <remote IP address>\r\n", ArgV[0]);
        RetVal = EINVAL;
        break;
      }

      //
      //  Bind the socket to a local port
      //
      printf("4\n");
      memset ( &LocalPort, 0, sizeof ( LocalPort ));
      SIN_LEN ( LocalPort ) = sizeof ( LocalPort );
      SIN_FAMILY ( LocalPort ) = AF_INET;
      SIN_ADDR ( LocalPort ) = 0;
      SIN_PORT ( LocalPort ) = 0;
      RetVal = bind ( s,
                      (struct sockaddr *)&LocalPort,
                      sizeof ( LocalPort ));
      if ( -1 == RetVal ) {
        RetVal = GET_ERRNO;
        printf ( "ERROR - bind error, errno: %d\r\n", RetVal );
        break;
      }
      printf("5\n");

      //
      //  Specify the remote port
      //
      memset ( &RemotePort, 0, sizeof ( RemotePort ));
      SIN_LEN ( RemotePort ) = sizeof ( RemotePort );
      SIN_FAMILY ( RemotePort ) = AF_INET;
      SIN_ADDR ( RemotePort ) = ( RemoteAddress[3] << 24 )
                              | ( RemoteAddress[2] << 16 )
                              | ( RemoteAddress[1] << 8 )
                              | RemoteAddress[0];
      SIN_PORT ( RemotePort ) = 0;
      printf("6\n");

      //
      //  Initialize the messages
      //
      memset ( &mBuffer[0], 0, sizeof ( mBuffer ));

      //
      //  Send the data before the out-of-band message
      //
      TotalSent = 0;
      BytesSent = 0;
      do {
        printf("7\n");
        BytesTransmitted = sendto ( s,
                                    &mBuffer[BytesSent],
                                    sizeof ( mBuffer ) - BytesSent,
                                    0,
                                    (struct sockaddr *)&RemotePort,
                                    sizeof ( RemotePort ));
        printf("8\n");
        if ( -1 == BytesTransmitted ) {
          RetVal = GET_ERRNO;
          printf ( "ERROR - send before error, errno: %d\r\n", RetVal );
          break;
        }
        BytesSent += (UINT32)BytesTransmitted;
        RetVal = 0;
      } while ( sizeof ( mBuffer ) > BytesSent );
      if ( 0 != RetVal ) {
        break;
      }
      TotalSent += BytesSent;

      //
      //  Test completed successfully
      //
      if ( 0 == RetVal ) {
        printf ( "Bytes sent:  %8d\r\n", TotalSent );
      }
      break;
    }

    //
    //  Close the socket
    //
    CLOSE_SOCKET ( s );
  }

  //
  //  Return the operation status
  //
  return RetVal;
}
