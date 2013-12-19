#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QtGui>
#include <QtCore>

class losedial : public QDialog
{

public:
    losedial(QWidget *parent=0):QDialog(parent)
    {
        this->setWindowFlags(Qt::Tool | Qt::CustomizeWindowHint);

        QVBoxLayout *prlay=new QVBoxLayout(this);
        QHBoxLayout *lay=new QHBoxLayout;

        QLabel *lab = new QLabel("You Lose");
        QPixmap win;
        win.load("C:/Users/Altair/Documents/Qt/Inversion/lose.png");
         lab->setPixmap(win);

        //lab->setWordWrap(true);

        prlay->addWidget(lab);
        QPushButton *m = new QPushButton("Quit");
        QPushButton *q = new QPushButton("Return");
        lay->addWidget(q);
        lay->addWidget(m);
        m->setFont(QFont("Comic Sans MS", 14));
        m->move(110, 50);
        q->setFont(QFont("Comic Sans MS", 14));
        prlay->addLayout(lay);
        connect(m, SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(q, SIGNAL(clicked()), this, SLOT(close()));
        //setWindowTitle(tr("Quitter"));
        setMinimumSize(160, 160);
        resize(400, 300);

        QDesktopWidget *widget = QApplication::desktop();
        int desktop_width = widget->width();
        int desktop_height = widget->height();
        int x = desktop_width / 2 - width() / 2;
        int y = desktop_height / 2 - height() / 2 - 25;
        move(QPoint(x, y));

    }

};

class windial : public QDialog
{

public:
    windial(QWidget *parent=0):QDialog(parent)
    {
        this->setWindowFlags(Qt::Tool | Qt::CustomizeWindowHint);

        QVBoxLayout *prlay=new QVBoxLayout(this);
        QHBoxLayout *lay=new QHBoxLayout;

        QLabel *lab = new QLabel;
        QPixmap win;
        win.load("C:/Users/Altair/Documents/Qt/Inversion/win.png");
         lab->setPixmap(win);
        //lab->setWordWrap(true);

        prlay->addWidget(lab);
        QPushButton *m = new QPushButton("Quit");
        QPushButton *q = new QPushButton("Return");
        lay->addWidget(q);
        lay->addWidget(m);
        m->setFont(QFont("Comic Sans MS", 14));
        m->move(110, 50);
        q->setFont(QFont("Comic Sans MS", 14));
        prlay->addLayout(lay);
        connect(m, SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(q, SIGNAL(clicked()), this, SLOT(close()));
        //setWindowTitle(tr("Quitter"));
        setMinimumSize(160, 160);
        resize(400, 300);

        QDesktopWidget *widget = QApplication::desktop();
        int desktop_width = widget->width();
        int desktop_height = widget->height();
        int x = desktop_width / 2 - width() / 2;
        int y = desktop_height / 2 - height() / 2 - 25;
        move(QPoint(x, y));

    }

};


class editdial : public QDialog
{

public:
    editdial(QWidget *parent=0):QDialog(parent)
    {
        this->setWindowFlags(Qt::Tool | Qt::CustomizeWindowHint);
        this->setStyleSheet("QWidget {  background-color: brown;border-style: outset; border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; }");

        QVBoxLayout *lay=new QVBoxLayout(this);

        QLabel *lab = new QLabel("This puzzle is unsolvable !!!");
        lab->setWordWrap(true);

        lay->addWidget(lab);
        QPushButton *m = new QPushButton("Cancel");
        lay->addWidget(m);
        m->setFont(QFont("Comic Sans MS", 14));
        m->move(110, 50);
        connect(m, SIGNAL(clicked()), this, SLOT(close()));
        setWindowTitle(tr("Menu Help"));
        setMinimumSize(160, 160);
        resize(400, 300);

        QDesktopWidget *widget = QApplication::desktop();
        int desktop_width = widget->width();
        int desktop_height = widget->height();
        int x = desktop_width / 2 - width() / 2;
        int y = desktop_height / 2 - height() / 2 - 25;
        move(QPoint(x, y));

    }

};


class helpdial : public QDialog
{

public:
    helpdial(QWidget *parent=0):QDialog(parent)
    {
        this->setWindowFlags(Qt::Tool | Qt::CustomizeWindowHint);


        this->setStyleSheet("QWidget {  background-color: brown;border-style: outset; border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; }");

        QVBoxLayout *lay=new QVBoxLayout(this);

        QLabel *lab = new QLabel("Lights-Out Help\n\n Aim: Press the buttons to turn off the lights.\n Other controls:\n Solve: Show shortest solution.Press Edit again to hide solution.\n Mix:   Randomly mix up the board.\n Reset: Clear the board.\n Edit:  Go to edit mode. Allows you to set up a position to solve. Press Edit again when finished.\n Choose the Puzzle: Select one of the 10 built-in puzzles.\n Play: start the game.Press Play again when finished.\n Quit :allow you to quit the game.");
        lab->setWordWrap(true);

        lay->addWidget(lab);
        QPushButton *m = new QPushButton("Cancel");
        lay->addWidget(m);
        m->setFont(QFont("Comic Sans MS", 14));
        m->move(110, 50);
        connect(m, SIGNAL(clicked()), this, SLOT(close()));
        setWindowTitle(tr("Menu Help"));
        setMinimumSize(160, 160);
        resize(480, 320);

        QDesktopWidget *widget = QApplication::desktop();
        int desktop_width = widget->width();
        int desktop_height = widget->height();
        int x = desktop_width / 2 - width() / 2;
        int y = desktop_height / 2 - height() / 2 - 25;
        move(QPoint(x, y));

    }

};
class quitdial : public QDialog
{

public:
    quitdial(QWidget *parent=0):QDialog(parent)
    {
        this->setWindowFlags(Qt::Tool | Qt::CustomizeWindowHint);

        QVBoxLayout *prlay=new QVBoxLayout(this);
        QHBoxLayout *lay=new QHBoxLayout;

        QLabel *lab = new QLabel("Are you sure you want to quit ?");
        lab->setWordWrap(true);

        prlay->addWidget(lab);
        QPushButton *m = new QPushButton("Quit");
        QPushButton *q = new QPushButton("Cancel");
        lay->addWidget(q);
        lay->addWidget(m);
        m->setFont(QFont("Comic Sans MS", 14));
        m->move(110, 50);
        q->setFont(QFont("Comic Sans MS", 14));
        prlay->addLayout(lay);
        connect(m, SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(q, SIGNAL(clicked()), this, SLOT(close()));
        setWindowTitle(tr("Quitter"));
        setMinimumSize(160, 160);
        resize(400, 200);

        QDesktopWidget *widget = QApplication::desktop();
        int desktop_width = widget->width();
        int desktop_height = widget->height();
        int x = desktop_width / 2 - width() / 2;
        int y = desktop_height / 2 - height() / 2 - 25;
        move(QPoint(x, y));

    }
};



class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow();
    bool solvable(int grid[][5],int * n1,int * n2);
    void givesol(int sol[][5],int grid[][5],int * n1,int * n2);
    int nbr (int* v);
    void add(int* src, int* v);
    void copy (int* src, int* dest);


public slots:
    //void opensound();
    void openhelp();
    void openquit();
    void openedit();
    void openreset();
    void openmix();
    void openplay();
    void opensolve();
    void openover();
    void opencombo(int);
    int isWin();
    void clik1();
    void clik2();

public :
    int gameTurns;
    int gameTimes;
    int gameScore;
    int isGameRun;
    int gamemin,gamesec;

    QPushButton *boutonQuitter ;
    QPushButton *edit;
    QPushButton *hel;
    QPushButton *player;
    QPushButton *resett;
    QPushButton *mix ;
    QPushButton *solve;
    QPushButton *test;
    QComboBox *combo ;
    QPushButton *soundplay;
    QPushButton *soundstop;
    QPushButton* b[5][5];
    QPixmap win;
    QPixmap lose;
    QSound* sound;

    QLabel *lblTurn;
    QLabel *lblTimes;
    QLabel *lblScore;
    QTimer *gameTimer;

private slots:
    void gameTimer_timeout();
    void refreshScore();

private:
    quitdial *quitdlg;
    helpdial *helpdlg;
    editdial *editdlg;
    losedial *losedlg;
    windial *windlg;
};

#endif // MAINDIALOG_H
