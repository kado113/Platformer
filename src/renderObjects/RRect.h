#ifndef RRECT_H
#define RRECT_H

#include "../IRenderObject.h"

class RRect : public IRenderObject
{
public:
    static RRect* create();
    static RRect* create(int x, int y, int w, int h);

protected:
    RRect();
    void render_self() override;

private:
    int m_coordX;
    int m_coordY;

    int m_width;
    int m_height;
};

#endif // RRECT_H
