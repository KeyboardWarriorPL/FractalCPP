#include "CustomSpinner.h"

QString CustomSpinner::textFromValue(int val) const {
    int len = QString::number(maximum(), 16).length();
    QString strval = QString::number(val, 16).toUpper();
    while (strval.length() < len) {
        strval.push_front('0');
    }
    return strval;
}
int CustomSpinner::valueFromText(const QString& tex) const {
    return tex.toInt(0, 16);
}
QValidator::State CustomSpinner::validate(QString& input, int& pos) const {
    QString copy{input};
    if (copy.startsWith("0x"))
        copy.remove(0, 2);
    pos -= copy.size() - copy.trimmed().size();
    if (copy.isEmpty())
        return QValidator::Intermediate;
    copy = copy.trimmed();
    input = QString("0x") + copy.toUpper();
    bool okay;
    int preval = input.toInt(&okay, 16);
    if (!okay || preval < minimum() || preval > maximum())
        return QValidator::Invalid;
    return QValidator::Acceptable;
}