#include <QtGui/QOpenGLFramebufferObject>
#include "mpvobject.h"

class MpvRenderer : public QQuickFramebufferObject::Renderer
{
    MpvObject *obj;

public:
    MpvRenderer(MpvObject *new_obj);
    virtual ~MpvRenderer()
    {}

    QOpenGLFramebufferObject * createFramebufferObject(const QSize &size);
    void render();
};
