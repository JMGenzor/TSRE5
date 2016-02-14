#include "SoundSourceObj.h"
#include "PoleObj.h"
#include "GLMatrix.h"
#include "TS.h"
#include "ParserX.h"
#include "FileBuffer.h"
#include "SoundList.h"
#include "Game.h"

SoundSourceObj::SoundSourceObj() {
}

SoundSourceObj::~SoundSourceObj() {
}

bool SoundSourceObj::allowNew(){
    return true;
}

bool SoundSourceObj::isSoundItem(){
    return true;
}

void SoundSourceObj::load(int x, int y) {
    this->x = x;
    this->y = y;
    this->position[2] = -this->position[2];
    Quat::fill(this->qDirection);
    this->loaded = true;

    setMartix();
}

void SoundSourceObj::set(QString sh, int val){
    if (sh == ("_refvalue")) {
        this->fileName = "";
        for (auto it = Game::soundList->sources.begin(); it != Game::soundList->sources.end(); ++it ){
            if(it->second->id == val){
                this->fileName = it->second->file1;
            }
        }
        return;
    }
    WorldObj::set(sh, val);
    return;
}

void SoundSourceObj::set(QString sh, QString val){
    if (sh == ("filename")) {
        fileName = val;
        return;
    }
    WorldObj::set(sh, val);
    return;
}

void SoundSourceObj::set(int sh, FileBuffer* data) {
    if (sh == TS::FileName) {
        data->off++;
        int slen = data->getShort()*2;
        fileName = *data->getString(data->off, data->off + slen);
        data->off += slen;
        return;
    }
    WorldObj::set(sh, data);
    return;
}

void SoundSourceObj::set(QString sh, FileBuffer* data) {
    if (sh == ("filename")) {
        fileName = ParserX::odczytajtc(data);
        return;
    }
    WorldObj::set(sh, data);
    return;
}

void SoundSourceObj::render(GLUU* gluu, float lod, float posx, float posz, float* pos, float* target, float fov, int selectionColor) {
    if (!loaded) return;
    Mat4::identity(gluu->objStrMatrix);
    Mat4::multiply(gluu->mvMatrix, gluu->mvMatrix, matrix);
    gluu->m_program->setUniformValue(gluu->mvMatrixUniform, *reinterpret_cast<float(*)[4][4]> (gluu->mvMatrix));
    gluu->m_program->setUniformValue(gluu->msMatrixUniform, *reinterpret_cast<float(*)[4][4]> (gluu->objStrMatrix));
    
    if(selectionColor != 0){
        int wColor = (int)(selectionColor/65536);
        int sColor = (int)(selectionColor - wColor*65536)/256;
        int bColor = (int)(selectionColor - wColor*65536 - sColor*256);
        gluu->disableTextures((float)wColor/255.0f, (float)sColor/255.0f, (float)bColor/255.0f, 1);
    } else {
        gluu->enableTextures();
    }
    
    if(pointer3d == NULL)
        pointer3d = new PoleObj();
        
    pointer3d->render(selectionColor);
};

void SoundSourceObj::save(QTextStream* out){
    if (!loaded) return;
    
*(out) << "	Soundsource (\n";
*(out) << "		Position ( "<<this->position[0]<<" "<<this->position[1]<<" "<<-this->position[2]<<" )\n";
*(out) << "		FileName ( "<<this->fileName<<" )\n";
*(out) << "		UiD ( "<<this->UiD<<" )\n";
*(out) << "	)\n";
}