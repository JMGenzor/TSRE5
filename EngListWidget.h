#ifndef ENGLISTWIDGET_H
#define	ENGLISTWIDGET_H

#include <QWidget>
#include <QtWidgets>

class EngListWidget : public QWidget {
    Q_OBJECT
public:
    EngListWidget();
    virtual ~EngListWidget();
    void fillEngList();
    
public slots:
    void itemsSelected();
        
signals:
    void engListSelected(int id);
        
private:
    QListWidget items;
    QComboBox engType;
    QComboBox couplingType;
};

#endif	/* ENGLISTWIDGET_H */
