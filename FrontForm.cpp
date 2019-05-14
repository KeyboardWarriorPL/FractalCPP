#include "FrontForm.h"

FrontForm::FrontForm(QMainWindow *parent) : QMainWindow(parent) {
    form.setupUi(this);
    scene = new QGraphicsScene;
    jgen = new Julia{1};
    QObject::connect(form.genButton, SIGNAL(clicked()), this, SLOT(drawFractal()));
}

void FrontForm::drawFractal() {
    QImage test{128,128, QImage::Format_RGB32};
    jgen->paint(test, 8, 0.42);
    scene->addPixmap(QPixmap::fromImage(test));
    form.graphicsView->setScene(scene);
}