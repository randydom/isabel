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
// $Id: pngImpl.hh 10568 2007-07-11 16:54:40Z gabriel $
//
/////////////////////////////////////////////////////////////////////////

#ifndef __png_implementation__hh__
#define __png_implementation__hh__

#include <vUtils/image.h>

image_t *pngLoadFile(FILE *f);

bool pngSaveFile(image_t *img, char *const path, bool addExt);

#endif
