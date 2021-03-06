/*
 *  bmpImage.h
 *  openc2e
 *
 *  Created by Alyssa Milburn on Wed Feb 20 2008.
 *  Copyright (c) 2008 Alyssa Milburn. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 */

#ifndef _BMPIMAGE_H
#define _BMPIMAGE_H

#include "fileformats/creaturesImage.h"
#include <memory>

class bmpImage;

class bmpData {
private:
	friend class bmpImage;

	bmpData(std::istream &in, std::string n);

	uint32_t biWidth, biHeight;
	uint32_t biCompression;
	std::vector<char> bmpdata;
	uint8_t *palette;
	imageformat imgformat;

public:
	~bmpData(); // shared_ptr needs to be able to call the destructor
};

class bmpImage : public creaturesImage {
protected:
	std::shared_ptr<bmpData> bmpdata;

public:
	bmpImage(std::istream &in, std::string n);
	~bmpImage();

	void setBlockSize(unsigned int blockwidth, unsigned int blockheight);

	bool hasCustomPalette() { return imgformat == if_paletted; }
	uint8_t *getCustomPalette() { return bmpdata->palette; }
};

#endif
/* vim: set noet: */
