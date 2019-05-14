#include "FrontForm.h"

FrontForm::FrontForm(QMainWindow *parent) : QMainWindow(parent) {
    form.setupUi(this);
    scene = new QGraphicsScene;
    jgen = new Julia{1};
    QObject::connect(form.genButton, SIGNAL(clicked()), this, SLOT(drawFractal()));
}

void FrontForm::drawFractal() {
    QImage test{form.graphicsView->width(), form.graphicsView->height(), QImage::Format_RGB32};
    jgen->rescale(form.zoomSpin->value());
    jgen->set(Polynomial({0,0,1}), Polynomial({1,0}));
    form.infoLabel->setText(jgen->ToString().data());
    FComplex cnst = FComplex{form.rSpin->value(), 2*M_PI*form.fiSlider->value()/form.fiSlider->maximum(), true};
    jgen->paint(test, form.iterSpin->value(), cnst);
    scene->clear();
    scene->addPixmap(QPixmap::fromImage(test));
    form.graphicsView->setScene(scene);
}