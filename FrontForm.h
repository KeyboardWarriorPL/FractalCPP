#include "ui_front.h"

class FrontForm : public QMainWindow {
    Q_OBJECT

    public:
    FrontForm(QMainWindow *parent) : QMainWindow(parent) {
        form.setupUi(this);
    }
    ~FrontForm() = default;

    private slots:
    private:
    Ui::Main form;
};