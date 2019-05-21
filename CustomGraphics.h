#pragma once
#include <QtGui/QMouseEvent>
#include <QtGui/QGraphicsView>
#include "Julia.h"

/// Extension of QGraphicsView supporting mouse press/release events
class CustomGraphics : public QGraphicsView {
    Q_OBJECT

    public:
    CustomGraphics(QWidget* parent = (QWidget*)0) : QGraphicsView(parent), source(nullptr) {}
    ~CustomGraphics() = default;

    Julia *source;

    protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

    private:
    QPoint mouse;
};