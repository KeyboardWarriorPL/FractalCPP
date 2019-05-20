#pragma once
#include "Julia.h"
#include "ui_front.h"
#include <QtGui/QFileDialog>
// #include <QtCore/QtConcurrentRun> not necessary since UI is updated synchronusly

class FrontForm : public QMainWindow {
    Q_OBJECT

    public:
    FrontForm(QMainWindow *parent);
    ~FrontForm() = default;

    private slots:
    void drawFractal();
    void saveImage();
    void resetPos();

    private:
    Ui::Main form;
    QImage *image;
    QGraphicsScene *scene;
    Julia *jgen;
};