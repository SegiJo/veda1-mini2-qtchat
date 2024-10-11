#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent) {} // 정의

void ClickableLabel::mousePressEvent(QMouseEvent *event) {
    emit clicked(); // 클릭 시 clicked 시그널 발생
    QLabel::mousePressEvent(event); // 기본 동작 수행
}
