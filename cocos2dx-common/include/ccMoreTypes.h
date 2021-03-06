/****************************************************************************
 Author: Luma (stubma@gmail.com)
 
 https://github.com/stubma/cocos2dx-common
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#ifndef __ccMoreTypes_h__
#define __ccMoreTypes_h__

#include "cocos2d.h"

USING_NS_CC;

NS_CC_BEGIN

/// hsv color
typedef struct ccColorHSV { float h, s, v; } ccColorHSV;
static inline ccColorHSV cchsv(const float h, const float s, const float v) {
	ccColorHSV c = { h, s, v };
	return c;
}

// aabb
typedef struct ccAABB { CCPoint min, max; } ccAABB;
static inline ccAABB ccaabb(const CCPoint min, const CCPoint max) {
	ccAABB b = {
		min,
		max
	};
	return b;
}

// position
typedef struct ccPosition { int x, y; } ccPosition;
static const ccPosition ccposZero = { 0, 0 };
static inline ccPosition ccpos(const int x, const int y) {
    ccPosition p = {
        x, y
    };
    return p;
}

// point struct
typedef struct ccPoint { float x, y; } ccPoint;
static const ccPoint ccpZero = { 0, 0 };
static inline ccPoint ccpt(const float x, const float y) {
	ccPoint p = { x, y };
	return p;
}
static inline ccPoint ccptAdd(const ccPoint& p1, const ccPoint& p2) {
	return ccpt(p1.x + p2.x, p1.y + p2.y);
}
static inline CCPoint ccp2CCP(const ccPoint& p) {
    return ccp(p.x, p.y);
}

// rect struct
typedef struct ccRect { float x, y, width, height; } ccRect;
static const ccRect ccrZero = { 0, 0, 0, 0 };
static inline ccRect ccr(const float x, const float y, const float w, const float h) {
	ccRect r = { x, y, w, h };
	return r;
}
static inline CCRect ccr2CCR(const ccRect& r) {
	return CCRectMake(r.x, r.y, r.width, r.height);
}

// size struct
typedef struct ccSize { float width, height; } ccSize;
static const ccSize ccsZero = { 0, 0 };
static inline ccSize ccsz(const float w, const float h) {
	ccSize s = { w, h };
	return s;
}

// rich font definition, support shadow color
struct ccRichFontDefinition : public ccFontDefinition {
    // font shadow color
    int m_shadowColor;
};

// color constants
static const ccColor4B cc4RED = { 255, 0, 0, 255 };
static const ccColor4B cc4GREEN = { 0, 255, 0, 255 };
static const ccColor4B cc4BLUE = { 0, 0, 255, 255 };
static const ccColor4B cc4BLACK = { 0, 0, 0, 255 };
static const ccColor4B cc4WHITE = { 255, 255, 255, 255 };
static const ccColor4B cc4TRANSPARENT = { 0, 0, 0, 0 };
static const ccColor4F cc4fRED = { 1, 0, 0, 1 };
static const ccColor4F cc4fGREEN = { 0, 1, 0, 1 };
static const ccColor4F cc4fBLUE = { 0, 0, 1, 1 };
static const ccColor4F cc4fBLACK = { 0, 0, 0, 1 };
static const ccColor4F cc4fWHITE = { 1, 1, 1, 1 };
static const ccColor4F cc4fTRANSPARENT = { 0, 0, 0, 0 };

/// convert int color 0xaarrggbb to ccColor4B
static inline ccColor4B ccc4FromInt(int c) {
    return ccc4((c >> 16) & 0xff,
                (c >> 8) & 0xff,
                c & 0xff,
                (c >> 24) & 0xff);
}

/// convert int color 0xaarrggbb to ccColor3B, alpha is discarded
static inline ccColor3B ccc3FromInt(int c) {
    return ccc3((c >> 16) & 0xff,
                (c >> 8) & 0xff,
                c & 0xff);
}

/// convert int color 0xaarrggbb to ccColor4F
static inline ccColor4F ccc4fFromInt(int c) {
    return ccc4f(((c >> 16) & 0xff) / 255.0f,
                ((c >> 8) & 0xff) / 255.0f,
                (c & 0xff) / 255.0f,
                ((c >> 24) & 0xff) / 255.0f);
}

/// convert ccColor4B to int color 0xaarrggbb
static inline int ccIntFromC4(const ccColor4B& c) {
    return ((c.a & 0xff) << 24) |
        ((c.r & 0xff) << 16) |
        ((c.g & 0xff) << 8) |
        (c.b & 0xff);
}

/// convert ccColor3B to int color 0xaarrggbb
static inline int ccIntFromC3(const ccColor3B& c) {
    return 0xff000000 |
        ((c.r & 0xff) << 16) |
        ((c.g & 0xff) << 8) |
        (c.b & 0xff);
}

/// convert ccColor4F to int color 0xaarrggbb
static inline int ccIntFromC4f(const ccColor4F& c) {
    return (((int)(c.a * 255) & 0xff) << 24) |
        (((int)(c.r * 255) & 0xff) << 16) |
        (((int)(c.g * 255) & 0xff) << 8) |
        ((int)(c.b * 255) & 0xff);
}

NS_CC_END

#endif // __ccMoreTypes_h__
