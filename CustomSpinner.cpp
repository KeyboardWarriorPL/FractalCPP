#include "CustomSpinner.h"

QString CustomSpinner::textFromValue(int val) const {
    return QString::number(val, 16).toUpper();
}
int CustomSpinner::valueFromText(const QString& tex) const {
    return tex.toInt(0, 16);
}
QValidator::State CustomSpinner::validate(QString& input, int& pos) const {
    if (input.isEmpty())
        return QValidator::Intermediate;
    input = input.toUpper();
    bool okay;
    int preval = input.toInt(&okay, 16);
    if (!okay || preval < minimum() || preval > maximum())
        return QValidator::Invalid;
    return QValidator::Acceptable;
}