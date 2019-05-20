#include "CustomGraphics.h"

void CustomGraphics::mousePressEvent(QMouseEvent* ev) {
    QGraphicsView::mousePressEvent(ev);
    mouse = QPoint{ev->x(), ev->y()};
}
void CustomGraphics::mouseReleaseEvent(QMouseEvent* ev) {
    QGraphicsView::mouseReleaseEvent(ev);
    QPoint result = QPoint{ev->x(), ev->y()};
    if (source != nullptr)
        source->reposition((double)(result.x() - mouse.x()) / 100.0, (double)(result.y() - mouse.y()) / 100.0);
}