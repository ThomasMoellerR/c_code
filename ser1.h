
/******************************************************************************

   File                :     ser1.h
   Version             :     11
   
   Version Temp-File   :     2
   
******************************************************************************/

#ifndef __SER1_H
#define __SER1_H

/******************************************************************************
   Include-Files
******************************************************************************/   

#include "typ.h"

/******************************************************************************
   Global Constants
******************************************************************************/   

//#define SER1_SENDING_MODE_POLLING				// Define it for mode polling
#define SER1_SENDING_MODE_DMA					// Define it for mode DMA

#define XOR_CHECKSUM							// Define it for XOR checksum

#define SER1_STX						0x65	// Start sign "A"
#define SER1_ETX						0x0D	// End sign (Carriage Return)

#define SER1_SNDBUF_QUELEN 				256 	// Length of send queue (Polling mode)
#define SER1_RECBUF_QUELEN 				256 	// Length of rec queue

#define SER1_SNDBUF_LEN					1024 	// Length of buffer for frame with payload to send
#define SER1_RECBUF_LEN					1024	// Length of payload buffer

/******************************************************************************
   Global Type-Definitions
******************************************************************************/   

/******************************************************************************
   Global Variables
******************************************************************************/   

// Sending
TUINT8 SER1_u8SendPollingRunning; 				// Indicates the polling state if polling is used. For DMA transfer not relevant
TUINT8 SER1_au8SndBuf[SER1_SNDBUF_LEN]; 		// Frame with payload to send
TUINT8 SER1_TransmitFrameLength;				// For DMA transfer

// Receiving
TUINT8 SER1_au8RecBuf[SER1_RECBUF_LEN]; 		// Extracted payload of received frame
TUINT8 SER1_u8ReceivedPayloadLength; 					// Number of data in received payload

/******************************************************************************
   Global Function-Prototypes
******************************************************************************/   

void SER1_Ini (void);

// Sending
void SER1_Send_Protocol (TUINT8* pu8Data, TUINT8 u8Len);	// Daten als Protokoll senden
void SER1_Send_String (TUINT8* pu8Data, TUINT8 u8Len); 		// Daten als roher String senden

// Receiving
TUINT8 SER1_u8Valid_Data(void); 							// Valid payload available?
void SER1_Protocol_Handling(TUINT8 u8Cycles); 				// Processing of the state machine for extracting the payload out of frame

// Ringbuffers
void SER1_SndBuf_Put (TUINT8 u8Data); 						// Send Queue
TUINT8 SER1_u8SndBuf_Get (void); 							// Send Queue
TUINT8 SER1_u8SndBuf_Empty (void); 							// Send Queue

void SER1_RecBuf_Put (TUINT8 u8Data); 						// Rec Queue
TUINT8 SER1_u8RecBuf_Get (void); 							// Rec Queue
TUINT8 SER1_u8RecBuf_Empty (void); 							// Rec Queue

#endif


