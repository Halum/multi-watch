#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class QWidget;
class QMouseEvent;

class ClickableLabel : public QLabel
{
  Q_OBJECT
public:
  explicit ClickableLabel(QWidget* parent = Q_NULLPTR);
  ~ClickableLabel();

signals:
  void clicked(ClickableLabel *label);

protected:
  void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL_H
