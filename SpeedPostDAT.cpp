#include "SpeedPostDAT.h"
#include <QDebug>
#include "Game.h"
#include "ParserX.h"
#include "ReadFile.h"
#include "SpeedPost.h"
#include "Game.h"

SpeedPostDAT::SpeedPostDAT() {
    QString sh;
    QString path = Game::root + "/routes/" + Game::route + "/speedpost.dat";
    path.replace("//", "/");
    qDebug() << path;
    QFile *file = new QFile(path);
    if (!file->open(QIODevice::ReadOnly))
        return;
    FileBuffer* bufor = ReadFile::read(file);
    bufor->off += 46;

    qDebug() << "speedpost!";
    while (!((sh = ParserX::nazwasekcji_inside(bufor).toLower()) == "")) {
        if (sh == "speed_warning_sign_shape") {
            this->speed_Warning_Sign_Shape = ParserX::odczytajtc(bufor);
            ParserX::pominsekcje(bufor);
            continue;
        }
        if (sh == "restricted_shape") {
            this->restricted_Shape = ParserX::odczytajtc(bufor);
            ParserX::pominsekcje(bufor);
            continue;
        }
        if (sh == "end_restricted_shape") {
            this->end_Restricted_Shape = ParserX::odczytajtc(bufor);
            ParserX::pominsekcje(bufor);
            continue;
        }
        if (sh == "speedpost_set") {
            this->speedPost.emplace_back();
            while (!((sh = ParserX::nazwasekcji_inside(bufor).toLower()) == "")) {
                this->speedPost.back().set(sh, bufor);
                ParserX::pominsekcje(bufor);
                continue;
            }
            ParserX::pominsekcje(bufor);
            continue;
        }
        qDebug() << sh;
        ParserX::pominsekcje(bufor);
        continue;
    }
    return;
}

SpeedPostDAT::~SpeedPostDAT() {
}

