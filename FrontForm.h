#pragma once
#include "Julia.h"
#include "ui_front.h"
#include <QtCore/QtConcurrentRun>
#include <QtGui/QFileDialog>
#include <QtGui/QMouseEvent>

class FrontForm : public QMainWindow {
    Q_OBJECT

    public:
    FrontForm(QMainWindow *parent);
    ~FrontForm() = default;

    protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

    private slots:
    void drawFractal();
    void saveImage();

    private:
    Ui::Main form;
    QImage *image;
    QGraphicsScene *scene;
    Julia *jgen;
    QPoint mouse;
};