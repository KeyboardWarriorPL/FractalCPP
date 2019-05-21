#pragma once
#include <QtGui/QSpinBox>

/// Hexadecimal QSpinBox
class CustomSpinner : public QSpinBox {
    Q_OBJECT

    public:
    CustomSpinner(QWidget* parent = (QWidget*)0) : QSpinBox(parent) {}
    ~CustomSpinner() = default;

    QString textFromValue(int val) const override;

    int valueFromText(const QString& tex) const override;

    QValidator::State validate(QString& input, int& pos) const override;
};