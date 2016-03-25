#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>

#include <memory>

#include "IRenderObject.h"

//pre-definitions
class IRenderCamera;



class RenderWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit RenderWidget(QWidget* parent = nullptr);
    ~RenderWidget();

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;


private:
    std::unique_ptr<IRenderObject> m_rootRenderObject;
//    std::unique_ptr<IRenderCamera> m_camera;

};

#endif // RENDERWIDGET_H
