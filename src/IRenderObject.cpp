#include "IRenderObject.h"

void IRenderObject::render()
{
    render_self();

    for( ChildPtr& ch : m_children )
    {
        ch->render();
    }
}

void IRenderObject::addChild(IRenderObject* ch)
{
    m_children.push_back(ChildPtr(ch));
}

void IRenderObject::addChild(ChildPtr ch)
{
    m_children.push_back(std::move(ch));
}

IRenderObject::IRenderObject(const IRenderObject& rhv)
{
    (void)rhv;
    //copying everything but child
}

IRenderObject::IRenderObject(IRenderObject&& rhv)
{
    m_children.swap(rhv.m_children);
}

void IRenderObject::copyChildren(IRenderObject* other)
{
    for( const ChildPtr& ch : other->m_children )
    {
        m_children.push_back(ChildPtr(ch->clone(true)));
    }
}

//---------------------------------------------- RRoot

RRoot* RRoot::clone(bool deepCopy)
{
    RRoot* ret_val = new RRoot(*this);

    if (deepCopy)
    {
        ret_val->copyChildren(this);
    }

    return ret_val;
}
