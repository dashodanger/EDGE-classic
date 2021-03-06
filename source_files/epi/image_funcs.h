//------------------------------------------------------------------------
//  Image Handling
//------------------------------------------------------------------------
// 
//  Copyright (c) 2003-2008  The EDGE Team.
//  Migrated to use stb_image in 2021 - Dashodanger
// 
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//------------------------------------------------------------------------

#ifndef __EPI_IMAGE_FUNCS_H__
#define __EPI_IMAGE_FUNCS_H__

#include "file.h"
#include "image_data.h"

namespace epi
{

const int JPEG_DEF_QUALITY = 90;

const int PNG_DEF_COMPRESS = 4;

bool PNG_IsDataPNG(const byte *data, int length);
// returns true if the data looks like a PNG file.

image_data_c *Image_Load(file_c *f, int read_flags, int format);
// loads the given image.  Returns 0 if something went wrong.
// The image will be RGB or RGBA (never paletted).  The size of
// image (width and height) will be rounded to the next highest
// power-of-two when 'read_flags' contains IRF_Round_POW2.

bool Image_GetInfo(file_c *f, int *width, int *height, bool *solid, int format);
// reads the principle information from the TGA header.
// (should be much faster than loading the whole image).
// Returns false if something went wrong.
// Note: size returned here is the real size, and may be different
// from the image returned by Load() which rounds to power-of-two.

bool JPEG_Save(const char *fn, image_data_c *img, int quality = JPEG_DEF_QUALITY);
// saves the image (in JPEG format) to the given file.  Returns false if
// something went wrong.  The 'quality' parameter is a percentage, the
// range is roughly 70 to 95 (values outside of this are possible).
// The image _MUST_ be RGB (bpp == 3).

bool PNG_Save(const char *fn, image_data_c *img, int compress = PNG_DEF_COMPRESS);
// saves the image (in PNG format) to the given file.  The compression
// level should be between 1 (Z_BEST_SPEED) and 9 (Z_BEST_COMPRESSION).
// Returns false if failed to save (e.g. file already exists).

}  // namespace epi

#endif  /* __EPI_IMAGE_JPEG_H__ */

//--- editor settings ---
// vi:ts=4:sw=4:noexpandtab
