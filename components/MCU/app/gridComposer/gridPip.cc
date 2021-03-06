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
// $Id: gridPip.cc 20759 2010-07-05 10:30:36Z gabriel $
//
/////////////////////////////////////////////////////////////////////////

#include "gridPip.h"

#include "../returnCode.h"
							   //W      H      X     Y
layout_t PipLayout[] = { { 16,  100.00,  100.00, 0.00, 0.00, MASK_NORMAL  },
                         { 16,  20.00,  20.00,  0.00,  0.00, MASK_INVERTED},
						 { 16,  20.00,  20.00, 80.00,  0.00, MASK_INVERTED},
                         { 16,  20.00,  20.00,  0.00, 80.00, MASK_INVERTED},
					     { 16,  20.00,  20.00, 80.00, 80.00, MASK_INVERTED},
                         { 16,  20.00,  20.00, 40.00,  0.00, MASK_INVERTED},
                         { 16,  20.00,  20.00, 40.00, 80.00, MASK_INVERTED},
						 { 16,  20.00,  20.00, 0.00,  40.00, MASK_INVERTED},
						 { 16,  20.00,  20.00, 80.00, 40.00, MASK_INVERTED},
						 { 16,  20.00,  20.00, 20.00,  0.00, MASK_INVERTED},
						 { 16,  20.00,  20.00, 20.00, 20.00, MASK_INVERTED},
                         { 16,  20.00,  20.00, 60.00,  0.00, MASK_INVERTED},
						 { 16,  20.00,  20.00, 20.00, 80.00, MASK_INVERTED},
						 { 16,  20.00,  20.00, 60.00, 80.00, MASK_INVERTED},
						 { 16,  20.00,  20.00,  0.00, 20.00, MASK_INVERTED},
						 { 16,  20.00,  20.00, 80.00, 20.00, MASK_INVERTED},
						 { 16,  20.00,  20.00,  0.00, 60.00, MASK_INVERTED},
						 { 16,  20.00,  20.00, 80.00, 60.00, MASK_INVERTED},
                         {-1,     -1,     -1}
                       };

							   //W      H      X     Y
layout_t CircleLayout[] = { { 5,  100.00, 100.00, 0.00,  0.00, MASK_NORMAL  },
                            { 5,  40.00,  40.00,  0.00,  0.00, MASK_INVERTED},
     				        { 5,  40.00,  40.00, 60.00,  0.00, MASK_INVERTED},
						    { 5,  40.00,  40.00,  0.00, 60.00, MASK_INVERTED},
                            { 5,  40.00,  40.00, 60.00, 60.00, MASK_INVERTED},
                            {-1,     -1,     -1}
                          };

int 
gridPip_t::search (int flowID) 
{	
	int pos= -1;
	int maxSize = layout[0].maxSize;
		
	for (int i= 0; i < maxSize; i++) {
		if (gridInfo[i].flowID == flowID)
			return i;
		if (gridInfo[i].kind != LEGAL && pos==-1)
			pos = i;
	}
	return pos;
}

gridPip_t::gridPip_t(gridMode_e mode,
					 unsigned int w,
					 unsigned int h)
:gridComposer_t(mode,w,h)
{
	switch(mode)
	{
	case GRID_PIP:
		{
			layout = PipLayout;
		}break;
	case GRID_CIRCLE:
		{
			layout = CircleLayout;
		}break;
	default:
		NOTIFY("gridPip_t::unknown mode\n");
	}

	for (u16 i = 0;layout[i].maxSize!=-1;i++)
	{
		gridInfo[i].flowID= -1;
		gridInfo[i].kind= EMPTY;
		gridInfo[i].window.w= (unsigned int)(layout[i].dW*Width/100.00);
		gridInfo[i].window.h= (unsigned int)(layout[i].dH*Height/100.00);
		gridInfo[i].window.x= (unsigned int)(layout[i].posX*Width/100.00);
		gridInfo[i].window.y= (unsigned int)(layout[i].posY*Height/100.00);
	}
}

gridPip_t::~gridPip_t(void)
{
}

HRESULT 
gridPip_t::addFlowID(int flowID) 
{
	int pos= search (flowID);
    if (pos == -1) 
	{
		NOTIFY("gridComposer_t:gridPip:there is no room for flowID %d\n",flowID);
	}else{
		gridInfo[pos].flowID= flowID;
		gridInfo[pos].kind= LEGAL;
	}
	return S_OK;
}

HRESULT 
gridPip_t::delFlowID(int flowID) 
{
	int pos= search(flowID);
	if (pos == -1) {
		NOTIFY("gridPip_t::delflowID: flowID %d unknown!", flowID);
        return E_ERROR;
	}
	gridInfo[pos].kind= DELETED;
	return S_OK;
}

maskType_e 
gridPip_t::getMask(int flowID)
{
	int pos= search(flowID);
	if (pos == -1) {
		NOTIFY("gridPip_t::delflowID: flowID %d unknown!", flowID);
        return MASK_NONE;
	}
	return layout[pos].mask;	
}
