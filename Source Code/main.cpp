#include "mainwindow.h"
#include <QtGui/QSplashScreen>
#include <QtGui/QApplication>
#include <windows.h>
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    MainWindow fenetre;
    int b=30;

    QSound::play("C:/Users/Altair/Documents/Qt/Inversion/intro.wav");

    QSplashScreen screen;
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/1.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/2.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/3.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/4.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/5.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash6.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/7.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/8.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/9.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/10.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/11.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/12.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/13.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/14.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/15.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/16.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/17.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/18.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/19.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/20.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/21.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/22.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/23.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/24.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/25.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/26.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/27.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/28.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/29.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/30.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/31.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/32.png"));
    screen.show();
    Sleep(1500);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/33.png"));
    screen.show();
    Sleep(100);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/34.png"));
    screen.show();
    Sleep(b);
    /////////////////
    screen.setPixmap(QPixmap("C:/Users/Altair/Documents/Qt/Inversion/splash/35.png"));
    screen.show();
    Sleep(b);
    screen.hide();

    fenetre.setWindowState(fenetre.windowState() ^ Qt::WindowFullScreen);
    // fenetre.frame.setFrameStyle(QFrame::StyledPanel);
    // fenetre.setStyleSheet("QWidget { background-image:url(./background.jpg); }");
    fenetre.show();


    return app.exec();
}


