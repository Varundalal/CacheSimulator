//VarunDalal
#include <QtGui>
#include <QSlider>
#include <QSpinBox>
#include <QRadioButton>
#include <QLabel>
#include <QComboBox>
#include <QStringList>
#include <QDial>
#include <QLCDNumber>
#include <QGridLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QAction>
#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <math.h>
#include <QTimer>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    textEdit = new QTextEdit;
    setCentralWidget(textEdit);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    createDockWindows();
     QTimer *timer = new QTimer(this);
            QObject::connect(timer, SIGNAL(timeout()), this, SLOT(calculate()));
            timer->start(100); //time specified in ms


    setWindowTitle(tr("Cache Simulator"));

    newLetter();
    setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::newLetter()
{
    textEdit->clear();
    textEdit->insertPlainText("Enter New text");
}

void MainWindow::print()
{
#ifndef QT_NO_PRINTDIALOG
    QTextDocument *document = textEdit->document();
    QPrinter printer;

    QPrintDialog *dlg = new QPrintDialog(&printer, this);
    if (dlg->exec() != QDialog::Accepted)
        return;

    document->print(&printer);

    statusBar()->showMessage(tr("Ready"), 2000);
#endif
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Text File"), "/home/user/", tr("Text Files (*.txt)"));
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
       file.open(QIODevice::ReadOnly);
       QTextStream textStream(&file);
       QString line = textStream.readAll();
       file.close();
       textEdit->setPlainText(line);

}

void MainWindow::save()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                        tr("Choose a file name"), ".",
                        tr("Text (*.txt)"));
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Dock Widgets"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << textEdit->toPlainText();
    QApplication::restoreOverrideCursor();

    statusBar()->showMessage(tr("Saved '%1'").arg(fileName), 2000);
}

void MainWindow::undo()
{
    QTextDocument *document = textEdit->document();
    document->undo();
}





void MainWindow::about()
{
   QMessageBox::about(this, tr("About Cache Simulator"),
            ("The goal of assignments I1 to I5 is to produce a user interface to a cache simulation application which"
              " enables evaluating cache design trade-offs. The UI has a component for the control of cache parameters"
              " such as type, size, associativity, etc. as well as parameters for display of performance e.g., hit ratio and"
              " miss ratio. The cache interfaces with a main memory that contains I bytes."
              " The cache is operating under one of three replacement policies: LRU, LFU, and Random. The cache can"
              " be either an instruction cache (I-Cache) or a data cache (D-Cache). The cache is set associative, with, N"
              " sets and L ways. Each way contains one block of K bytes of instructions or data and several control bits."
              " The performance simulator reads a trace file (trace of memory access instances), evaluates the result of"
              " each access and updates the state of the cache following each access. The trace file – contains a list of"
              " memory access instances in Hex format with one access per trace line: e.g.,"
              " 0xabcd14"
              " 0xabcd18"
              " The simulation control includes instructions for 1) Start, 2) Go, 3) Step S (S is the number of trace"
              " elements to be processed before stopping, and 4) Break B (stop at trace element B)."
              " The simulator output includes: 1) Indication that the system is operating, 2) a fractal indicating that the"
              " system is waiting for input 3) Graphs with visualization of a) the number of memory access instances b)"
              " hit ratio, c) compulsory miss Ratio, and d) miss ratio. In addition, the app has the ability to store results"
             "  in a report file."));
}

void MainWindow::createActions()
{
    newLetterAct = new QAction(QIcon(":/images/new.png"), tr("&New Letter"),
                               this);
    newLetterAct->setShortcuts(QKeySequence::New);
    newLetterAct->setStatusTip(tr("Create a new form letter"));
    connect(newLetterAct, SIGNAL(triggered()), this, SLOT(newLetter()));

    openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open new text"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));


    saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save..."), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the current text"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    printAct = new QAction(QIcon(":/images/print.png"), tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the current text"));
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

    undoAct = new QAction(QIcon(":/images/undo.png"), tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo the last editing action"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    quitAct = new QAction(tr("&Quit"), this);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Quit the application"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newLetterAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);

    viewMenu = menuBar()->addMenu(tr("&View"));

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newLetterAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(printAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(undoAct);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDockWindows()
{
    QDockWidget *dock = new QDockWidget(tr("Simulator"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    window1 = new QWidget(dock);
    QLabel *la = new QLabel("INPUT");
    QLabel *lb = new QLabel("OUTPUT");
    QLabel *l1 = new QLabel("Cache Type");
    QRadioButton *rb1 = new QRadioButton("Instruction Cache");
    QRadioButton *rb2 = new QRadioButton("Data Cache");
    QLabel *l2 = new QLabel("Replacement Policy");
    QComboBox *c1 = new QComboBox();
    QStringList list=(QStringList()<<"Select"<<"Least Recently Used"<<"Least Frequently Used"<<"Random");
    c1->addItems(list);
    QLabel *l3 = new QLabel("Number Of Sets");
    spinBox = new QSpinBox;                          //N
    spinBox->setRange(0, 100);
    spinBox->setValue(10);

    QLabel *l10 = new QLabel("Main Memory Size (Enter 2^M");
    sB1 = new QSpinBox;                              //M
    sB1->setRange(2,28);
    sB1->setValue(15);




    QLabel *l4 = new QLabel("Number Of Ways");
    spinBox1 = new QSpinBox;                         //L
    QSlider *slider1 = new QSlider(Qt::Horizontal);
    spinBox1->setRange(0, 100);
    slider1->setRange(0, 100);
    QObject::connect(spinBox1, SIGNAL(valueChanged(int)),
    slider1, SLOT(setValue(int)));
    QObject::connect(slider1, SIGNAL(valueChanged(int)),
    spinBox1, SLOT(setValue(int)));
    spinBox1->setValue(75);

    QLabel *l5 = new QLabel("Number Of Bytes/block");
    d1 = new QDial();                                   //k
    QLCDNumber *lc1 = new QLCDNumber();
    lc1->setStyleSheet("*{background-color: yellow; color: red}");
    d1->setRange(0,100);
    d1->setValue(30);
    QObject::connect(d1, SIGNAL(valueChanged(int)),
                     lc1,SLOT(display(int)));

    QLabel *l6 = new QLabel("Size Of Reference Word");
    QLabel *l7 = new QLabel("Size Of Offset Field");
    QLabel *l8 = new QLabel("Size Of Index Field");
    QLabel *l9 = new QLabel("Size Of Tag Field");
    QLabel *l101 = new QLabel("Memory Access Instance");
    QLabel *l11 = new QLabel("Hit Ratio");
    QLabel *l12 = new QLabel("Compulsory Miss Ratio");
    QLabel *l13 = new QLabel("Miss Ratio");



    lc2 = new QLCDNumber();
    lc2->setStyleSheet("*{background-color: green; color: red}");

    lc3 = new QLCDNumber();
    lc3->setStyleSheet("*{background-color: green; color: red}");
    lc4 = new QLCDNumber();
    lc4->setStyleSheet("*{background-color: green; color: red}");
    lc5 = new QLCDNumber();
    lc5->setStyleSheet("*{background-color: green; color: red}");
    QLCDNumber *lc6 = new QLCDNumber();
    lc6->setStyleSheet("*{background-color: green; color: red}");
    QLCDNumber *lc7 = new QLCDNumber();
    lc7->setStyleSheet("*{background-color: green; color: red}");
    QLCDNumber *lc8 = new QLCDNumber();
    lc8->setStyleSheet("*{background-color: green; color: red}");
    QLCDNumber *lc9 = new QLCDNumber();
    lc9->setStyleSheet("*{background-color: green; color: red}");

    QPushButton *quit = new QPushButton(("Quit"));
    quit->setFont(QFont("Times", 12, QFont::Bold));
    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(sB1, SIGNAL(valueChanged(int)), this, SLOT(setM(int)));
    calculate();
    connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(setN(int)));
    calculate();
    connect(d1, SIGNAL(valueChanged(int)), this, SLOT(setK(int)));
    calculate();
    connect(spinBox1, SIGNAL(valueChanged(int)), this, SLOT(setL(int)));
    calculate();
    QPushButton *start = new QPushButton(("Start"));
    start->setFont(QFont("Times", 13, QFont::Bold));
    QPushButton *go = new QPushButton(("Go"));
    go->setFont(QFont("Times", 13, QFont::Bold));
    QPushButton *step = new QPushButton(("Step"));
    step->setFont(QFont("Times", 13, QFont::Bold));
    QPushButton *brk = new QPushButton(("Break"));
    brk->setFont(QFont("Times", 13, QFont::Bold));




    QGridLayout *grid = new QGridLayout;

    grid->addWidget(la,1,0);
    grid->addWidget(l2,2,0);
    grid->addWidget(c1,3,0);
    grid->addWidget(l1,4,0);
    grid->addWidget(rb1,5,0);
    grid->addWidget(rb2,6,0);
    grid->addWidget(l10,7,0);
    grid->addWidget(sB1,8,0);
    grid->addWidget(l3,9,0);
    grid->addWidget(spinBox,10,0);
    grid->addWidget(l4,11,0);
    grid->addWidget(slider1,12,0);
    grid->addWidget(spinBox1,13,0);
    grid->addWidget(l5,14,0);
    grid->addWidget(d1,15,0);
    grid->addWidget(lc1,16,0);
    grid->addWidget(lb,1,2);
    grid->addWidget(l6,2,2);
    grid->addWidget(lc2,3,2);
    grid->addWidget(l7,4,2);
    grid->addWidget(lc3,5,2);
    grid->addWidget(l8,6,2);
    grid->addWidget(lc4,7,2);
    grid->addWidget(l9,8,2);
    grid->addWidget(lc5,9,2);
    grid->addWidget(l101,2,3);
    grid->addWidget(lc6,3,3);
    grid->addWidget(l11,4,3);
    grid->addWidget(lc7,5,3);
    grid->addWidget(l12,6,3);
    grid->addWidget(lc8,7,3);
    grid->addWidget(l13,8,3);
    grid->addWidget(lc9,9,3);

    grid->addWidget(start,12,2);
    grid->addWidget(go,12,3);
    grid->addWidget(step,13,2);
    grid->addWidget(brk,13,3);



    grid->addWidget(quit,18,3);

    window1->setLayout(grid);
    dock->setWidget(window1);
    addDockWidget(Qt::RightDockWidgetArea, dock);

}
void MainWindow::setM(int value)
{
sB1->setValue(value);
}

void MainWindow::setN(int value)
{
spinBox->setValue(value);
}

void MainWindow::setK(int value)
{
d1->setValue(value);
}

void MainWindow::setL(int value)
{
spinBox1->setValue(value);
}
void MainWindow::calculate()
{

    int m = sB1->value();
    int n = spinBox->value();
    int k = d1->value();
    int l = spinBox1->value();
    int m1 =  ceil(log(2^(m))/log(2));
    int n1 =  ceil(log(n)/log(2));
    int k1 =  ceil(log(k)/log(2));
    int l1 =  m1-n1-k1;
    lc2->display(m1);
    lc3->display(n1);
    lc4->display(k1);
    lc5->display(l1);
    qDebug("m1 = %d",m1);

}
