/////////////////////////////////////////////////////////////////////////
//
// ISABEL: A group collaboration tool for the Internet
// Copyright (C) 2009 Agora System S.A.
// 
// This file is part of Isabel.
// 
// Isabel is free software: you can redistribute it and/or modify
// it under the terms of the Affero GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Isabel is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Affero GNU General Public License for more details.
// 
// You should have received a copy of the Affero GNU General Public License
// along with Isabel.  If not, see <http://www.gnu.org/licenses/>.
//
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
//
// $Id: outputDriver.cc 20206 2010-04-08 10:55:00Z gabriel $
//
// (C) Copyright 1993-99. Dpto Ingenieria Sistemas Telematicos UPM Spain
// Dec 31, 1999 Transfered to Agora Systems S.A.
// (C) Copyright 2000-2001. Agora Systems S.A.
//
/////////////////////////////////////////////////////////////////////////



#include "outputDriver.hh"
#include "messages.hh"

outputDriver_t::outputDriver_t(io_ref &io): threadedTask_t(io), _outIo(io) {
}

outputDriver_t::~outputDriver_t() {
}

bool
outputDriver_t::dispatchMsg(tlMsg_t *tlMsg) {

     switch (tlMsg->msgKind) {
         case PKTMSG_ID: {
             pktMsg_t *pktMsg = static_cast<pktMsg_t *>(tlMsg);
             int len=_outIo->write(pktMsg->pktBuff->data, pktMsg->pktLen);
             if (len!= pktMsg->pktLen) 
                 fprintf(stderr, "outputDriver_t::dispatchMsg:: ERROR "
                         "when writing a packet!!\n");

         } break;

         default:
             return threadedTask_t::dispatchMsg(tlMsg);
     }

     return true;
}

