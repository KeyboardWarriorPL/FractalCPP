#include "FrontForm.h"

FrontForm::FrontForm(QMainWindow *parent) : QMainWindow(parent) {
    form.setupUi(this);
    scene = new QGraphicsScene;
    jgen = new Julia{1};
    image = new QImage{form.graphicsView->width(), form.graphicsView->height(), QImage::Format_RGB32};
    QObject::connect(form.genButton, SIGNAL(clicked()), this, SLOT(drawFractal()));
    QObject::connect(form.savButton, SIGNAL(clicked()), this, SLOT(saveImage()));
    form.graphicsView->source = jgen;
}

void FrontForm::drawFractal() {
    delete image;
    image = new QImage{form.graphicsView->width(), form.graphicsView->height(), QImage::Format_RGB32};
    jgen->rescale(form.zoomSpin->value());
    jgen->colormap((form.redSpin->value()<<16) + (form.greenSpin->value()<<8) + form.blueSpin->value());
    jgen->set(Polynomial(form.fText->toPlainText().toStdString()), Polynomial(form.gText->toPlainText().toStdString()));
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
