#pragma once
#include <QtGui/QMouseEvent>
#include <QtGui/QGraphicsView>
#include "Julia.h"

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