#include "CustomGraphics.h"

void CustomGraphics::mousePressEvent(QMouseEvent* ev) {
    QGraphicsView::mousePressEvent(ev);
    setCursor(Qt::ClosedHandCursor);
    mouse = QPoint{ev->x(), ev->y()};
}
void CustomGraphics::mouseReleaseEvent(QMouseEvent* ev) {
    QGraphicsView::mouseReleaseEvent(ev);
    setCursor(Qt::OpenHandCursor);
    QPoint result = QPoint{ev->x(), ev->y()};
    int dx = mouse.x() - result.x(), dy = mouse.y() - result.y();
    if (source != nullptr)
        source->reposition(dx, dy);
}