//
//  CubeMap.cpp
//  NoiseSphere
//
//  Created by masahidey on 2014/04/02.
//
//

#include "CubeMap.h"

void CubeMap::setFromImages(int size, ofImage img_px, ofImage img_nx, ofImage img_py, ofImage img_ny, ofImage img_pz, ofImage img_nz)
{
 	glGenTextures(1, &textureObject);
	glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, textureObject);

    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, GL_RGBA, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, img_px.getPixels());
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB, 0, GL_RGBA, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, img_nx.getPixels());
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB, 0, GL_RGBA, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, img_py.getPixels());
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB, 0, GL_RGBA, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, img_ny.getPixels());
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB, 0, GL_RGBA, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, img_pz.getPixels());
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB, 0, GL_RGBA, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, img_nz.getPixels());

	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void CubeMap::bind()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, textureObject);
}

void CubeMap::unbind()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, 0 );
}
