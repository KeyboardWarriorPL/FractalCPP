#include "FrontForm.h"
#include <iostream>

FrontForm::FrontForm(QMainWindow *parent) : QMainWindow(parent) {
    form.setupUi(this);
    scene = new QGraphicsScene;
    jgen = new Julia{1};
    image = new QImage{form.graphicsView->width(), form.graphicsView->height(), QImage::Format_RGB32};
    QObject::connect(form.genButton, SIGNAL(clicked()), this, SLOT(drawFractal()));
    QObject::connect(form.savButton, SIGNAL(clicked()), this, SLOT(saveImage()));
    QObject::connect(form.resetButton, SIGNAL(clicked()), this, SLOT(resetPos()));
    form.graphicsView->source = jgen;
}

void FrontForm::drawFractal() {
    delete image;
    image = new QImage{form.graphicsView->width(), form.graphicsView->height(), QImage::Format_RGB32};
    jgen->rescale(form.zoomSpin->value());
    jgen->set(Polynomial(form.fText->toPlainText().toStdString()), Polynomial(form.gText->toPlainText().toStdString()));
    jgen->colormap(form.colorSpin->value(), form.shiftSpin->value());
    FComplex cnst = FComplex{form.rSpin->value(), 2*M_PI*form.fiSlider->value()/form.fiSlider->maximum(), true};
    form.infoLabel->setText(cnst.ToString().data());

    jgen->paint(*image, form.iterSpin->value(), cnst, form.progressBar);

    scene->clear();
    scene->addPixmap(QPixmap::fromImage(*image));
    form.graphicsView->setScene(scene);
}

void FrontForm::saveImage() {
    QString path = QFileDialog::getSaveFileName(this, "Save as", ".png", ".png");
    if (path.size() > 0)
        image->save(path);
}

void FrontForm::resetPos() {
    Polynomial test{"1z^2 - 3,3z^3 + 3,56 + 1 + (2+3,3i)z^5 + 1,2z +3z"};
    cout << test.ToString() << endl;
    // debug end
    jgen->reposition(0,0,true);
}
