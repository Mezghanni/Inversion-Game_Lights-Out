#include "mainwindow.h"

int grid[5][5]={1};
int sol[5][5]={0};
int n1[25]= {1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,1};
int  n2[25]= {1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1};


MainWindow::MainWindow()
{
    quitdlg=0;
    editdlg=0;
    helpdlg=0;
    windlg=0;
    losedlg=0;

    //QSound::play("C:/Users/Altair/Documents/Qt/Inversion/sound.wav");

    QGridLayout* layout1 = new QGridLayout();
    QHBoxLayout* layout4 = new QHBoxLayout();

    QVBoxLayout *layout3 = new QVBoxLayout;

    for  (int i=0; i < 5; i++)
    {
        for  (int j=0; j < 5; j++)
        {   b[i][j] = new QPushButton(this);
            grid[i][j]=1;
            b[i][j]->setStyleSheet(" QPushButton {  border-image: url(C:/Users/Altair/Documents/Qt/Inversion/on.png) 1 1 1 1 ;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
            b[i][j]->setMinimumSize(100, 100);
            layout1->addWidget(b[i][j], i, j);
        }
    }


    combo= new QComboBox();
    QLabel *label = new QLabel("Choose the puzzle :");
    label->setFixedSize(40,40);
    combo->addItem("--");
    for (int i=1;i<=10;i++){
        combo->addItem("Puzzle "+QString::number(i));
    }
    connect(combo,SIGNAL(currentIndexChanged(int)),this,SLOT(opencombo(int)));
    combo->setFixedSize(40,40);
    combo->setStyleSheet("QWidget {  background-color: gray;border-style: outset;}");
    layout3->addWidget(label);
    layout3->addWidget(combo);


    layout4->addLayout(layout3);


    layout4->addLayout(layout1);
    QVBoxLayout *layout6= new QVBoxLayout();
    gameTurns=0;gameTimes=0;
    gameScore=0;gamemin=0;gamesec=0;
    lblTurn = new QLabel(this);
    lblTurn->setFixedSize(30, 30);
    layout6->addWidget(lblTurn);

    lblTimes = new QLabel(this);
    lblTimes->setFixedSize(30, 30);
    layout6->addWidget(lblTimes);

    lblScore = new QLabel(this);
    lblScore->setFixedSize(30, 30);
    layout6->addWidget(lblScore);

    QSound* sound=new QSound("C:/Users/Altair/Documents/Qt/Inversion/sound.wav");
    sound->setLoops(-1);

    soundplay = new QPushButton(this);
    soundplay->setMaximumSize(100, 100);
    soundplay->setStyleSheet("QPushButton{border-image: url(C:/Users/Altair/Documents/Qt/Inversion/sound.png)3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
    QObject::connect(soundplay,SIGNAL(clicked()),sound,SLOT(play()));
    layout6->addWidget(soundplay);
    soundstop = new QPushButton(this);
    soundstop->setMaximumSize(100, 100);
    soundstop->setStyleSheet("QPushButton{border-image: url(C:/Users/Altair/Documents/Qt/Inversion/mute.png)3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
    QObject::connect(soundstop,SIGNAL(clicked()),sound,SLOT(stop()));
    layout6->addWidget(soundstop);

    layout4->addLayout(layout6);

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("QWidget {background: url('C:/Users/Altair/Documents/Qt/Inversion/back.png')no-repeat ; border-style: outset; border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; }");
    QVBoxLayout *layoutPrincipal=new QVBoxLayout(this);

    QHBoxLayout *layout2=new QHBoxLayout();
    quitdlg= new quitdial(this);
    helpdlg= new helpdial(this);
    editdlg= new editdial(this);
    windlg= new windial(this);
    losedlg= new losedial(this);


    player= new QPushButton("Play");
    player->setCheckable(true);
    player->setStyleSheet(" QPushButton {  border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton.png) 3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
    connect(player, SIGNAL(clicked()), this, SLOT(openplay()));
    connect(player, SIGNAL(clicked()), this, SLOT(clik2()));


    player->setMinimumSize(50,50);
    layout2->addWidget(player);


    solve = new QPushButton("Solve");
    solve->setCheckable(true);
    solve->setStyleSheet(" QPushButton {  border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton.png) 3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
    solve->setMinimumSize(50,50);
    solve->setEnabled(false);
    connect(solve, SIGNAL(clicked()), this, SLOT(opensolve()));
    layout2->addWidget(solve);

    mix= new QPushButton("Mix");
    mix->setStyleSheet(" QPushButton {  border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton.png) 3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
    mix->setMinimumSize(50,50);
    connect(mix, SIGNAL(clicked()), this, SLOT(openmix()));

    layout2->addWidget(mix);

    resett = new QPushButton("Reset");
    resett->setMinimumSize(50,50);
    resett->setStyleSheet(" QPushButton {  border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton.png) 3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
    connect(resett, SIGNAL(clicked()), this, SLOT(openreset()));
    layout2->addWidget(resett);

    edit = new QPushButton("Edit");
    edit->setMinimumSize(50,50);
    edit->setStyleSheet(" QPushButton {  border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton.png) 3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
    edit->setCheckable(true);
    connect(edit, SIGNAL(clicked()), this, SLOT(openedit()));
    connect(edit, SIGNAL(clicked()), this, SLOT(clik1()));
    layout2->addWidget(edit);

    hel = new QPushButton("Help");
    hel->setMinimumSize(50,50);
    hel->setStyleSheet(" QPushButton {  border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton.png) 3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
    connect(hel, SIGNAL(clicked()), this, SLOT(openhelp()));
    layout2->addWidget(hel);

    boutonQuitter = new QPushButton("Quit");
    boutonQuitter->setMinimumSize(50,50);
    boutonQuitter->setStyleSheet(" QPushButton {  border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton.png) 3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
    QWidget::connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(openquit()));
    layout2->addWidget(boutonQuitter);

    layoutPrincipal->addLayout(layout2);



    layoutPrincipal->addLayout(layout4);
    this->resize(1370,600);
    setLayout(layoutPrincipal);

    gameTimer = new QTimer();
    gameTimer->setInterval(1000);
    gameTimer->start();
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(gameTimer_timeout()));


    refreshScore();

}

void MainWindow::openquit()
{  quitdlg->setStyleSheet("QWidget {  background-color: brown;border-style: outset; border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; }");
    quitdlg->setModal(true);
    quitdlg->show();

}

void MainWindow::openhelp()
{  helpdlg->setStyleSheet("QWidget {  background-color: brown;border-style: outset; border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; }");
    helpdlg->setModal(true);
    helpdlg->show();

}

void MainWindow::openedit()
{   if (resett->isEnabled()==true)
    {
        resett->setEnabled(false);
        mix->setEnabled(false);
        solve->setEnabled(false);
        combo->setEnabled(false);
        edit->setStyleSheet("QPushButton{border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton-clicked.png)3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");

        for  (int i=0; i < 5; i++)
        {
            for  (int j=0; j < 5; j++)
            {
                b[i][j]->setCheckable(true);
                connect(b[i][j], SIGNAL(clicked()), this, SLOT(clik1()));

            }
        }
    }
    else
    {   resett->setEnabled(true);
        mix->setEnabled(true);
        solve->setEnabled(true);
        combo->setEnabled(true);
        edit->setStyleSheet("QPushButton{border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton.png)3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
        solve->setEnabled(false);

        if (!solvable(grid,n1,n2))
        {
            editdlg->setStyleSheet("QWidget {  background-color: brown;border-style: outset; border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; }");
            editdlg->setModal(true);
            editdlg->show();

        }

    }

}
void MainWindow::clik1()
{

    if (edit->isChecked())
    {

        for  (int l=0; l < 5; l++)
            for  (int c=0; c < 5; c++)
            {  if (b[l][c]->isChecked()) {
                    grid[l][c]+=1;
                    grid[l][c]%=2;
                    b[l][c]->setChecked(false);
                    for(int i=0;i<5;i++)
                    {
                        for(int j=0;j<5;j++)
                            if (grid[i][j]==1)
                            {b[i][j]->setStyleSheet("QPushButton {border-image: url(C:/Users/Altair/Documents/Qt/Inversion/on.png) ;}");}else
                            {b[i][j]->setStyleSheet("QPushButton { border-image: url(C:/Users/Altair/Documents/Qt/Inversion/off.png) ; }");}
                    }

                }
            }

    }

}
void MainWindow::openmix()
{
    do{       for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
                grid[i][j]=(rand()%2);
        }
    }while(!solvable(grid,n1,n2));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            if (grid[i][j]==1)
            {b[i][j]->setStyleSheet("QPushButton {border-image: url(C:/Users/Altair/Documents/Qt/Inversion/on.png) ;}");}else
            {b[i][j]->setStyleSheet("QPushButton { border-image: url(C:/Users/Altair/Documents/Qt/Inversion/off.png) ; }");}
    }

}
void MainWindow::openplay()
{      if (resett->isEnabled()==true)
    {   resett->setEnabled(false);
        mix->setEnabled(false);
        edit->setEnabled(false);
        combo->setEnabled(false);
        player->setStyleSheet("QPushButton{border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton-clicked.png)3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
        solve->setEnabled(true);
        if (!solve->isChecked()) isGameRun=1;
        for  (int i=0; i < 5; i++)
        {
            for  (int j=0; j < 5; j++)
            {
                b[i][j]->setCheckable(true);
                connect(b[i][j], SIGNAL(clicked()), this, SLOT(clik2()));

            }
        }
    }
    else
    {   isGameRun=0;
        gameTurns=0;
        gameTimes=0;
        gameScore=0;
        gamemin=0;gamesec=0;
        resett->setEnabled(true);
        mix->setEnabled(true);
        edit->setEnabled(true);
        combo->setEnabled(true);
        player->setStyleSheet("QPushButton{border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton.png)3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
        solve->setEnabled(false);
    }
}
void MainWindow::clik2()
{

    if (player->isChecked())
    {

        for  (int l=0; l < 5; l++)
            for  (int c=0; c < 5; c++)
            {  if (b[l][c]->isChecked()) {
                    if (!solve->isChecked())
                        gameTurns++;
                    grid[l][c]+=1;
                    grid[l][c]%=2;
                    if (l+1>=0 && l+1<5)
                    {grid[l+1][c]+=1;grid[l+1][c]%=2;}
                    if (c+1>=0 && c+1<5)
                    {grid[l][c+1]+=1;grid[l][c+1]%=2;}
                    if (l-1>=0 && l-1<5)
                    {grid[l-1][c]+=1;grid[l-1][c]%=2;}
                    if (c-1>=0 && c-1<5)
                    {grid[l][c-1]+=1;grid[l][c-1]%=2;}
                    b[l][c]->setChecked(false);
                    if (!solve->isChecked()) openover();
                    givesol(sol,grid,n1,n2);
                    for(int i=0;i<5;i++)
                    {
                        for(int j=0;j<5;j++)
                        {if (grid[i][j]==1)
                            {b[i][j]->setStyleSheet("QPushButton {border-image: url(C:/Users/Altair/Documents/Qt/Inversion/on.png) ;}");}else
                            {b[i][j]->setStyleSheet("QPushButton { border-image: url(C:/Users/Altair/Documents/Qt/Inversion/off.png) ; }");}
                            if (solve->isChecked())
                            {if (sol[i][j]==3)
                                {
                                    if (grid[i][j]==1)
                                    {b[i][j]->setStyleSheet("QPushButton {border-image: url(C:/Users/Altair/Documents/Qt/Inversion/ons.png) ;}");}else
                                    {b[i][j]->setStyleSheet("QPushButton { border-image: url(C:/Users/Altair/Documents/Qt/Inversion/offs.png) ; }");}
                                }
                            }
                        }

                    }

                }
            }
    }

}
void MainWindow::opencombo(int k)
{  int grille[5][5]={0};
    switch(k){
    case 1 :{int g[6][5]={{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,1}};
        for  (int i=0; i < 5; i++)for  (int j=0; j < 5; j++)grille[i][j]=g[i][j];
        break;}
    case 2 :{int g[6][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,1,0,0},{0,1,1,1,0},{1,1,1,1,1}};
        for  (int i=0; i < 5; i++)for  (int j=0; j < 5; j++)grille[i][j]=g[i][j];
        break;}
    case 3 :{int g[6][5]={{0,0,1,0,0},{0,1,0,1,0},{1,0,1,0,1},{0,1,0,1,0},{0,0,1,0,0}};
        for  (int i=0; i < 5; i++)for  (int j=0; j < 5; j++)grille[i][j]=g[i][j];
        break;}
    case 4 :{int g[6][5]={{1,0,1,0,1},{0,0,0,0,0},{1,0,1,0,1},{0,0,0,0,0},{1,0,1,0,1}};
        for  (int i=0; i < 5; i++)for  (int j=0; j < 5; j++)grille[i][j]=g[i][j];
        break;}
    case 5 :{int g[6][5]={{0,0,0,0,0},{0,0,0,0,0},{1,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0}};
        for  (int i=0; i < 5; i++)for  (int j=0; j < 5; j++)grille[i][j]=g[i][j];
        break;}
    case 6 :{int g[6][5]={{0,1,1,1,1},{0,1,0,0,0},{0,1,1,1,0},{0,1,0,0,0},{0,1,0,0,0}};
        for  (int i=0; i < 5; i++)for  (int j=0; j < 5; j++)grille[i][j]=g[i][j];
        break;}
    case 7 :{int g[6][5]={{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}};
        for  (int i=0; i < 5; i++)for  (int j=0; j < 5; j++)grille[i][j]=g[i][j];
        break;}
    case 8 :{int g[6][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,1,1,1},{0,0,1,1,0},{0,0,1,0,0}};
        for  (int i=0; i < 5; i++)for  (int j=0; j < 5; j++)grille[i][j]=g[i][j];
        break;}
    case 9 :{int g[6][5]={{0,0,0,0,0},{0,0,0,0,0},{1,0,0,0,1},{1,1,1,1,1},{0,1,0,0,1}};
        for  (int i=0; i < 5; i++)for  (int j=0; j < 5; j++)grille[i][j]=g[i][j];
        break;}
    case 10 :{int g[6][5]={{1,0,0,0,0},{1,1,0,0,0},{1,1,1,0,0},{1,1,1,1,0},{0,1,1,1,1}};
        for  (int i=0; i < 5; i++)for  (int j=0; j < 5; j++)grille[i][j]=g[i][j];
        break;}
    }
    for  (int i=0; i < 5; i++)
    {
        for  (int j=0; j < 5; j++)
        {
            grid[i][j]=grille[i][j];
            b[i][j]->setCheckable(false);
            if (grille[i][j]==1)
                b[i][j]->setStyleSheet("QPushButton {border-image: url(C:/Users/Altair/Documents/Qt/Inversion/on.png) ;}");
            else   b[i][j]->setStyleSheet("QPushButton {border-image: url(C:/Users/Altair/Documents/Qt/Inversion/off.png) ;}");

        }
    }
}


void MainWindow::openreset()
{
    for  (int i=0; i < 5; i++)
    {
        for  (int j=0; j < 5; j++)
        {   grid[i][j]=1;
            b[i][j]->setCheckable(false);
            b[i][j]->setStyleSheet("QPushButton {border-image: url(C:/Users/Altair/Documents/Qt/Inversion/on.png) ;}");
        }
    }
}
void MainWindow::opensolve()
{   if (solve->isChecked()==true)
    {  solve->setStyleSheet("QPushButton{border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton-clicked.png)3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");
    }
    else
        solve->setStyleSheet("QPushButton{border-image: url(C:/Users/Altair/Documents/Qt/Inversion/bouton.png)3 10 3 10;color: grey;border-top: 3px transparent; border-bottom: 3px transparent;border-right: 10px transparent;border-left: 10px transparent;}");


    isGameRun=0;

    givesol(sol,grid,n1,n2);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            if (sol[i][j]==3)
            {
                if (grid[i][j]==1)
                {b[i][j]->setStyleSheet("QPushButton {border-image: url(C:/Users/Altair/Documents/Qt/Inversion/ons.png) ;}");}else
                {b[i][j]->setStyleSheet("QPushButton { border-image: url(C:/Users/Altair/Documents/Qt/Inversion/offs.png) ; }");}
            }
    }


}


bool MainWindow::solvable(int grid[][5],int * n1,int * n2)
{
    int cur[25];
    int nbr;
    for (int i=0; i<25; i++) {
        if (grid[i%5] [i/5]) {
            cur[i] = 1; }
        else {
            cur[i] = 0; }
    }
    nbr = 0;
    for (int i=0; i<25; i++) {
        nbr = (nbr + cur[i]*n1[i])%2;
    }
    if (nbr != 0) { return(false); }
    nbr = 0;
    for (int i=0; i<25; i++) {
        nbr = (nbr + cur[i]*n2[i])%2;
    }
    if (nbr != 0) { return(false); }
    else { return(true); }
}

void MainWindow::givesol (int sol[][5],int grid[][5],int * n1,int * n2)
{
    int hint_matrix[23][23] = {
        { 0,1,1,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0 },
        { 1,1,0,1,1,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0 },
        { 1,0,1,1,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,1,0,1,0 },
        { 1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1 },
        { 0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,1,1,0 },
        { 0,0,1,0,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0 },
        { 0,1,0,1,0,1,1,0,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0 },
        { 1,0,1,0,0,1,0,1,1,0,0,0,0,0,1,1,0,1,0,1,1,0,1 },
        { 0,0,1,0,0,0,1,1,1,0,1,0,0,1,1,1,0,0,1,0,0,1,1 },
        { 1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,1 },
        { 0,0,0,0,1,0,0,0,1,1,0,0,1,0,1,1,1,1,1,0,0,1,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1 },
        { 0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,0,0,1,1,0 },
        { 1,1,1,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0 },
        { 1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,1,0,1,0,0 },
        { 0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,0,1,1,0,1 },
        { 0,0,1,1,0,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,0,0,1 },
        { 0,0,1,0,1,0,1,1,0,1,1,0,1,0,0,1,1,0,1,1,1,0,0 },
        { 0,1,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,1,0,0,0,1 },
        { 1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1 },
        { 0,0,0,1,1,0,0,1,0,0,0,1,1,0,1,1,0,1,0,1,1,1,0 },
        { 0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1 },
        { 0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,0,1,0 }};
    int current_state[23];
    int hint_vector[25];
    for (int i=0; i<25; i++) {
        hint_vector[i] = 0;
    }
    for (int i=0; i<23; i++) {
        if (grid[i%5][i/5]) {
            current_state[i] = 1; }
        else {
            current_state[i] = 0; }
    }
    for (int i=0; i<23; i++) {
        for (int j=0; j<23; j++) {
            hint_vector[i] =
                    (hint_vector[i] + current_state[j]*hint_matrix[i][j])%2;
        }
    }
    int optimal[25];
    int aux[25];
    copy(hint_vector,optimal);
    copy(hint_vector,aux);
    add(aux,n1);
    if ( nbr(aux) < nbr(optimal) ) {
        copy(aux,optimal);
    }
    copy(hint_vector,aux);
    add(aux,n2);
    if ( nbr(aux) < nbr(optimal) ) {
        copy(aux,optimal);
    }
    copy(hint_vector,aux);
    add(aux,n1);
    add(aux,n2);
    if ( nbr(aux) < nbr(optimal) ) {
        copy(aux,optimal);
    }
    for (int i=0; i<25; i++) {
        if (optimal[i] == 1) { sol[i%5][i/5]=3; }
        else { sol[i%5][i/5]=4; }
    }
}


void MainWindow::copy (int* src, int* dest)
{
    for (int i=0; i<25; i++) {
        dest[i] = src[i];
    }
}



void MainWindow::add(int* src, int* v)
{
    for (int i=0; i<25; i++) {
        src[i] = (src[i] + v[i]) %2 ;
    }
}



int MainWindow::nbr (int* v)
{
    int t=0;
    for (int i=0; i < 25; i++) {
        t = t + v[i];
    }
    return(t);
}


void MainWindow::refreshScore(){
    gameScore=1000-(gameTurns)-(gameTimes);
    if(gameScore<0)gameScore=0;

    gamesec=gameTimes%60;
    gamemin=(gameTimes-gamesec)/60;
    lblTurn->setText(tr("Turns")+": "+QString::number(gameTurns));
    lblTimes->setText(tr("Times")+": "+QString::number(gamemin)+":"+QString::number(gamesec));
    lblScore->setText(tr("Score")+": "+QString::number(gameScore));
}
void MainWindow::gameTimer_timeout(){
    if (isGameRun==1) gameTimes++;
    refreshScore();
}

void MainWindow::openover(){
    if (isWin()==1){
        isGameRun=0;
        windlg->setStyleSheet("QWidget {  background-color: brown;border-style: outset; border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; }");
        windlg->setModal(true);
        windlg->show();

    }
    if (gameScore==0)
    {isGameRun=0;
        losedlg->setStyleSheet("QWidget {  background-color: brown;border-style: outset; border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; }");
        losedlg->setModal(true);
        losedlg->show();
    }
}


int MainWindow::isWin(){
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){

            if (grid[i][j]==1) return 0;
        }
    }

    return 1;
}

