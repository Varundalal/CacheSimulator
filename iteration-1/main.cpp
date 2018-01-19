/* Varun Dalal */
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
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
int main(int argc, char *argv[])
    {
        QApplication app(argc, argv);
        QWidget *window = new QWidget;
        window->setStyleSheet("*{background-color: skyblue;}");
        window->setWindowTitle("Cache Simulator developed by Varun Dalal");
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
        QSpinBox *spinBox = new QSpinBox;
        spinBox->setRange(0, 100);
        spinBox->setValue(0);


        QLabel *l4 = new QLabel("Number Of Ways");
        QSpinBox *spinBox1 = new QSpinBox;
        QSlider *slider1 = new QSlider(Qt::Horizontal);
        spinBox1->setRange(0, 100);
        slider1->setRange(0, 100);
        QObject::connect(spinBox1, SIGNAL(valueChanged(int)),
        slider1, SLOT(setValue(int)));
        QObject::connect(slider1, SIGNAL(valueChanged(int)),
        spinBox1, SLOT(setValue(int)));
        spinBox1->setValue(50);

        QLabel *l5 = new QLabel("Number Of Bytes/block");
        QDial *d1 = new QDial();
        QLCDNumber *lc1 = new QLCDNumber();
        lc1->setStyleSheet("*{background-color: yellow; color: red}");
        d1->setRange(0,100);
        QObject::connect(d1, SIGNAL(valueChanged(int)),
                         lc1,SLOT(display(int)));

        QLabel *l6 = new QLabel("Memory Access Instances");
        QLabel *l7 = new QLabel("Hit Ratio");
        QLabel *l8 = new QLabel("Cumpolsary Miss Ratio");
        QLabel *l9 = new QLabel("Miss Ratio");
        QLCDNumber *lc2 = new QLCDNumber();
        lc2->setStyleSheet("*{background-color: green; color: red}");
        QLCDNumber *lc3 = new QLCDNumber();
        lc3->setStyleSheet("*{background-color: green; color: red}");
        QLCDNumber *lc4 = new QLCDNumber();
        lc4->setStyleSheet("*{background-color: green; color: red}");
        QLCDNumber *lc5 = new QLCDNumber();
        lc5->setStyleSheet("*{background-color: green; color: red}");

        QPushButton *quit = new QPushButton(("Quit"));
        quit->setFont(QFont("Times", 12, QFont::Bold));
        QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));


        QGridLayout *grid = new QGridLayout;

        grid->addWidget(la,0,0);

       
        grid->addWidget(l2,1,0);
        grid->addWidget(c1,2,0);
        grid->addWidget(l1,3,0);
        grid->addWidget(rb1,4,0);
        grid->addWidget(rb2,5,0);
        grid->addWidget(l3,6,0);
        grid->addWidget(spinBox,7,0);
        grid->addWidget(l4,8,0);
        grid->addWidget(slider1,9,0);
        grid->addWidget(spinBox1,10,0);
        grid->addWidget(l5,11,0);
        grid->addWidget(d1,12,0);
        grid->addWidget(lc1,13,0);
        grid->addWidget(lb,0,2);
        grid->addWidget(l6,1,2);
        grid->addWidget(lc2,2,2);
        grid->addWidget(l7,3,2);
        grid->addWidget(lc3,4,2);
        grid->addWidget(l8,5,2);
        grid->addWidget(lc4,6,2);
        grid->addWidget(l9,7,2);
        grid->addWidget(lc5,8,2);
        grid->addWidget(quit,16,2);





        window->setLayout(grid);
        window->show();
        return app.exec();
      }

/*

 */
