#ifndef MAINWINDOW_H
 #define MAINWINDOW_H

 #include <QMainWindow>
 #include "qcustomplot.h"

 class QAction;
 class QListWidget;
 class QMenu;
 class QTextEdit;
 class QSpinBox;
 class QDial;
 class QLCDNumber;
 class QPushButton;
 class QString;
 class GLobj;
 class GLobj1;






 class MainWindow : public QMainWindow
 {
     Q_OBJECT

 public:
     MainWindow();
     GLobj *globj;
     GLobj *obj1;
     void plotGraph(QCustomPlot *customPlot, float a, float b, float c, float t);



 private slots:
     void generateTrace();
     void readTrace();
     void newLetter();
     void open();
     void save();
     void print();
     void undo();
     void about();
     void setM(int value);
     void setN(int value);
     void setK(int value);
     void setL(int value);
     void calculate();



 private:
     void createActions();
     void createMenus();
     void createToolBars();
     void createStatusBar();
     void createDockWindows();


     QLCDNumber *lc2 ;
     QLCDNumber *lc3 ;
     QLCDNumber *lc4 ;
     QLCDNumber *lc5 ;

     QSpinBox *spinBox;
     QSpinBox *sB1;
     QSpinBox *spinBox1;
     QDial *d1;
     QWidget *window1;
     QWidget *window2;

     QTextEdit *textEdit;
     QString str;



     QMenu *fileMenu;
     QMenu *editMenu;
     QMenu *viewMenu;
     QMenu *helpMenu;
     QToolBar *fileToolBar;
     QToolBar *editToolBar;
     QAction *openAct;
     QAction *newLetterAct;
     QAction *saveAct;
     QAction *printAct;
     QAction *undoAct;
     QAction *aboutAct;
     QAction *aboutQtAct;
     QAction *quitAct;
     QPushButton *openTraceAct;

 };

 #endif
