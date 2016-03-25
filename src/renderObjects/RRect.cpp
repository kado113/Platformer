#include "RRect.h"

/* static */
RRect* RRect::create()
{
    RRect* ret_val = new RRect;
    return ret_val;
}

RRect::RRect()
    : m_coordX(0)
    , m_coordY(0)
    , m_width(0)
    , m_height(0)
{

}

/* static */
RRect* create(int x, int y, int w, int h)
{
    RRect* ret_val = new RRect;
    ret_val->m_coordX = x;
    ret_val->m_coordY = y;
    ret_val->m_width = w;
    ret_val->m_height = h;

    return ret_val;
}

/* virtual */
void RRect::render_self()
{

}
