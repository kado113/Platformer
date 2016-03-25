#ifndef IRENDEROBJECT_H
#define IRENDEROBJECT_H

#include <memory>
#include <list>


class IRenderObject
{
public:
    using ChildPtr = std::unique_ptr<IRenderObject>;
    using ChildrenArray = std::list<ChildPtr>;

public:
    //public IF:

    static IRenderObject* create();

    void render();
    void addChild(IRenderObject* ch);
    void addChild(ChildPtr ch);

    void copyChildren(IRenderObject* other);
protected:
    IRenderObject() {}
    IRenderObject(const IRenderObject& rhv);
    IRenderObject(IRenderObject&& rhv);
protected:
    //
    virtual IRenderObject* clone(bool deepCopy) = 0;
    virtual void render_self() = 0;

protected:
    ChildrenArray m_children;
};


//Render Root Object
class RRoot : public IRenderObject
{
public:
    static RRoot* create() { return new RRoot; }

    RRoot* clone(bool deepCopy = true) override;
protected:
    void render_self() override {}
};


#endif // IRENDEROBJECT_H

