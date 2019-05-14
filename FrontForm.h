#pragma once
#include "Julia.h"
#include "ui_front.h"

class FrontForm : public QMainWindow {
    Q_OBJECT

    public:
    FrontForm(QMainWindow *parent);
    ~FrontForm() = default;

    private slots:
    void drawFractal();

    private:
    Ui::Main form;
    QGraphicsScene *scene;
    Julia *jgen;
};