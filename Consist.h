/*  This file is part of TSRE5.
 *
 *  TSRE5 - train sim game engine and MSTS/OR Editors. 
 *  Copyright (C) 2016 Piotr Gadecki <pgadecki@gmail.com>
 *
 *  Licensed under GNU General Public License 3.0 or later. 
 *
 *  See LICENSE.md or https://www.gnu.org/licenses/gpl.html
 */

#ifndef CONSIST_H
#define	CONSIST_H

#include <QString>
#include <unordered_map>

class Eng;
class TextObj;
class FileBuffer;
class QTextStream;

class Consist {
public:
    static std::unordered_map<int, TextObj*> txtNumbers;
    static int lastTxtNumbersColor;
    int lastTxtColor;
    static TextObj * txtEngineE;
    static TextObj * txtEngineD;
    static TextObj * txtEngineS;
    static TextObj * txtEngineF;
    static TextObj * txtEngineW;
    static TextObj * txtEngineT;
    struct EngItem{
        bool flip = false;
        int uid = 0;
        int eng = -1;
        float pos = 0;
        float conLength = 0;
        int type = 0;
        TextObj * txt = NULL;
        QString epath;
        QString ename;
    };
    Consist();
    Consist(Consist * con);
    virtual ~Consist();
    QString name;
    QString path;
    QString pathid;
    QString conName;
    QString displayName;
    QString showName;
    unsigned int serial = 0;
    float maxVelocity[2];
    int nextWagonUID = 0;
    float durability = 0;
    float conLength = 0;
    float mass = 0;
    float emass = 0;
    int loaded = -1;
    bool kierunek = false;
    int ref = 0;
    int posInit = false;
    int selectedIdx = -1;
    float textColor[3];
    std::vector<EngItem> engItems;
    Consist(QString p, QString n);
    Consist(QString src, QString p, QString n);
    void load();
    bool load(FileBuffer* data);
    void save();
    void save(QString woff, QTextStream *out);
    void select(int idx);
    void appendEngItem(int id);
    void appendEngItem(int id, int pos = 2, bool flip = false);
    void deteleSelected();
    void flipSelected();
    void moveLeftSelected();
    void moveRightSelected();
    bool isNewConsist();
    bool isBroken();
    bool isUnSaved();
    void setModified(bool val);
    void setNewConsistFlag();
    void setFileName(QString n);
    void setDisplayName(QString n);
    void reverse();
    void setTextColor(float *bgColor);
    void setDurability(float val);
    void render(int selectionColor = 0, bool renderText = false);
    void render(int aktwx, int aktwz, int selectionColor, bool renderText);
    void initPos();
    void setMaxVelocityFixed(bool val);
    bool isMaxVelocityFixed();
    QString getFirstEngName();
private:
    bool newConsist = false;
    bool modified = false;
    bool defaultValue = false;
    bool maxVelocityFixed = false;
};

#endif	/* CONSIST_H */

