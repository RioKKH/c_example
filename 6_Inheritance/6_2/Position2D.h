#ifndef _POSITION2D_H_
#define _POSITION2D_H_

// 継承する場合には、継承元のクラスを定義しているファイルを読み込んでく必要がある
#include "Vector2D.h"

class Position2D : public Vector2D {
public:
    // reset the position
    void resetPosition();
    // move the position
    void move(int dx, int dy);
};

#endif // _POSITION2D_H_
        
