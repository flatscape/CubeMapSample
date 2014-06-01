//
//  CubeMap.h
//  NoiseSphere
//
//  Created by masahidey on 2014/04/02.
//
//

#ifndef __NoiseSphere__CubeMap__
#define __NoiseSphere__CubeMap__

#include "ofMain.h"

class CubeMap
{
private:
    unsigned int textureObject;
public:
    void setFromImages(
                       int size,
                       ofImage img_px, ofImage img_nx,
                       ofImage img_py, ofImage img_ny,
                       ofImage img_pz, ofImage img_nz
                       );
    void bind();
    void unbind();
};

#endif /* defined(__NoiseSphere__CubeMap__) */
