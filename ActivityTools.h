/*  This file is part of TSRE5.
 *
 *  TSRE5 - train sim game engine and MSTS/OR Editors. 
 *  Copyright (C) 2016 Piotr Gadecki <pgadecki@gmail.com>
 *
 *  Licensed under GNU General Public License 3.0 or later. 
 *
 *  See LICENSE.md or https://www.gnu.org/licenses/gpl.html
 */

#ifndef ACTIVITYTOOLS_H
#define	ACTIVITYTOOLS_H

#include <QtWidgets>
#include <QString>

class Route;

class ActivityTools : public QWidget{
    Q_OBJECT
public:
    ActivityTools(QString name);
    virtual ~ActivityTools();

public slots:
    void loadActFiles();
    void fillConListAct(QString n);
    void routeLoaded(Route* r);
    
signals:    

private:
    Route *route = NULL;
    QListWidget consists;
    QComboBox actShow;
};

#endif	/* ACTIVITYTOOLS_H */

