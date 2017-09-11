/*  This file is part of TSRE5.
 *
 *  TSRE5 - train sim game engine and MSTS/OR Editors. 
 *  Copyright (C) 2016 Piotr Gadecki <pgadecki@gmail.com>
 *
 *  Licensed under GNU General Public License 3.0 or later. 
 *
 *  See LICENSE.md or https://www.gnu.org/licenses/gpl.html
 */

#ifndef PATH_H
#define	PATH_H


#include <QString>
#include "GLUU.h"
#include "GameObj.h"
#include "TDB.h"

class OglObj;

class Path : public GameObj {
    Q_OBJECT
public:
    static void CreatePaths(TDB * tdb);
    
    struct PathNode {
        unsigned int flags;
        unsigned int next;
        unsigned int next2;
        int tilex;
        int tilez;
        float pos[3];
        unsigned int flag1;
        unsigned int flag2;
    };
    
    QString displayName;
    QString name;
    QString nameId;
    QString path;
    QString pathid;  
    QString pathId;
    QString trPathName;
    QString trPathStart;
    QString trPathEnd;
    unsigned int trPathFlags;
    
    QVector<float*> trackPdp;
    QVector<unsigned int*> trPathNode;
    QVector<PathNode> node;
    
    Path();
    Path(QString p, QString n, bool nowe = false);
    Path(const Path& orig);
    virtual ~Path();
    void load();
    void initRoute();
    void init3dShapes();
    bool isModified();
    void render(GLUU* gluu, float * playerT, int renderMode);
private:
    int loaded;
    bool modified = false;
    bool isinit = false;
    int serial = -1;
    TrackItemObj* pointer3d = NULL;
    QVector<OglObj*> lines;
    QVector<float> linesX;
    QVector<float> linesZ;
};

#endif	/* PATH_H */

