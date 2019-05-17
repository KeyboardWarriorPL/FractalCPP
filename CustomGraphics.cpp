#include "CustomGraphics.h"

void CustomGraphics::mousePressEvent(QMouseEvent* ev) {
    QGraphicsView::mousePressEvent(ev);
    mouse = QPoint{ev->x(), ev->y()};
}
void CustomGraphics::mouseReleaseEvent(QMouseEvent* ev) {
    QGraphicsView::mouseReleaseEvent(ev);
    QPoint result = QPoint{ev->x(), ev->y()};
    if (source != nullptr)
        source->reposition((double)(result.x() - mouse.x()) * 10.0 / width(), (double)(result.y() - mouse.y()) * 10.0 / height());
}