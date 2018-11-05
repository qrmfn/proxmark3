//-----------------------------------------------------------------------------
// Copyright (C) 2018 Merlok
// Copyright (C) 2018 drHatson
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// iso14443-4 mifare commands
//-----------------------------------------------------------------------------

#ifndef MIFARE4_H
#define MIFARE4_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
	bool Authenticated;
	uint8_t Key[16];
	uint16_t KeyNum;
	uint8_t RndA[16];
	uint8_t RndB[16];
	uint8_t TI[4];
	uint8_t PICCap2[6];
	uint8_t PCDCap2[6];
	uint8_t Kenc[16];
	uint8_t Kmac[16];
	uint16_t R_Ctr;
	uint16_t W_Ctr;
}mf4Session;

typedef enum {
	mtypReadCmd,
	mtypReadResp,
	mtypWriteCmd,
	mtypWriteResp,
} MACType_t;

extern int CalculateMAC(mf4Session *session, MACType_t mtype, uint8_t blockNum, uint8_t blockCount, uint8_t *data, int datalen, uint8_t *mac, bool verbose);
extern int MifareAuth4(mf4Session *session, uint8_t *keyn, uint8_t *key, bool activateField, bool leaveSignalON, bool verbose);

extern uint8_t mfNumBlocksPerSector(uint8_t sectorNo);
extern uint8_t mfFirstBlockOfSector(uint8_t sectorNo);
extern uint8_t mfSectorTrailer(uint8_t blockNo);
extern bool mfIsSectorTrailer(uint8_t blockNo);
extern uint8_t mfSectorNum(uint8_t blockNo);


#endif // mifare4.h
