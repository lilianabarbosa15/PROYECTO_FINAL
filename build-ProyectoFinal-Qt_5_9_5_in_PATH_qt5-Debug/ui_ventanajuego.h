/********************************************************************************
** Form generated from reading UI file 'ventanajuego.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAJUEGO_H
#define UI_VENTANAJUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaJuego
{
public:
    QAction *actionMusica;
    QAction *actionSonidos;
    QAction *actionSobrePersonajes;
    QAction *actionHistoria;
    QAction *actionInstrucciones;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaJuego)
    {
        if (VentanaJuego->objectName().isEmpty())
            VentanaJuego->setObjectName(QStringLiteral("VentanaJuego"));
        VentanaJuego->resize(700, 500);
        VentanaJuego->setMinimumSize(QSize(700, 500));
        VentanaJuego->setMaximumSize(QSize(700, 500));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(168, 233, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(211, 244, 247, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(84, 116, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(112, 155, 160, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        VentanaJuego->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral(":/iconos/iconW_nave.png"), QSize(), QIcon::Normal, QIcon::Off);
        VentanaJuego->setWindowIcon(icon);
        actionMusica = new QAction(VentanaJuego);
        actionMusica->setObjectName(QStringLiteral("actionMusica"));
        actionMusica->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/iconos/icon_no_music.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/iconos/icon_music.png"), QSize(), QIcon::Normal, QIcon::On);
        actionMusica->setIcon(icon1);
        actionSonidos = new QAction(VentanaJuego);
        actionSonidos->setObjectName(QStringLiteral("actionSonidos"));
        actionSonidos->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/iconos/icon_no_sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/iconos/icon_sound.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSonidos->setIcon(icon2);
        actionSobrePersonajes = new QAction(VentanaJuego);
        actionSobrePersonajes->setObjectName(QStringLiteral("actionSobrePersonajes"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/iconos/icon_info_personaje.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSobrePersonajes->setIcon(icon3);
        actionHistoria = new QAction(VentanaJuego);
        actionHistoria->setObjectName(QStringLiteral("actionHistoria"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/iconos/icon_history.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHistoria->setIcon(icon4);
        actionInstrucciones = new QAction(VentanaJuego);
        actionInstrucciones->setObjectName(QStringLiteral("actionInstrucciones"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/iconos/icon_info_instrucciones.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInstrucciones->setIcon(icon5);
        centralwidget = new QWidget(VentanaJuego);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 420, 188, 40));
        pushButton->setMinimumSize(QSize(188, 40));
        pushButton->setMaximumSize(QSize(188, 40));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: white;\n"
"	border-width: 3px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 680, 400));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 420, 188, 40));
        pushButton_2->setMinimumSize(QSize(188, 40));
        pushButton_2->setMaximumSize(QSize(188, 40));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: white;\n"
"	border-width: 3px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 430, 89, 25));
        VentanaJuego->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaJuego);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 22));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName(QStringLiteral("menuOpciones"));
        VentanaJuego->setMenuBar(menubar);
        statusbar = new QStatusBar(VentanaJuego);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        VentanaJuego->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionMusica);
        menuOpciones->addAction(actionSonidos);
        menuOpciones->addAction(actionSobrePersonajes);
        menuOpciones->addAction(actionHistoria);
        menuOpciones->addAction(actionInstrucciones);

        retranslateUi(VentanaJuego);

        QMetaObject::connectSlotsByName(VentanaJuego);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaJuego)
    {
        VentanaJuego->setWindowTitle(QApplication::translate("VentanaJuego", "MainWindow", Q_NULLPTR));
        actionMusica->setText(QApplication::translate("VentanaJuego", "&Musica", Q_NULLPTR));
        actionSonidos->setText(QApplication::translate("VentanaJuego", "&Efectos de sonido", Q_NULLPTR));
        actionSobrePersonajes->setText(QApplication::translate("VentanaJuego", "&Sobre personajes", Q_NULLPTR));
        actionHistoria->setText(QApplication::translate("VentanaJuego", "&Historia", Q_NULLPTR));
        actionInstrucciones->setText(QApplication::translate("VentanaJuego", "&Instrucciones", Q_NULLPTR));
        pushButton->setText(QApplication::translate("VentanaJuego", "Jugar", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("VentanaJuego", "Pausar", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("VentanaJuego", "back", Q_NULLPTR));
        menuOpciones->setTitle(QApplication::translate("VentanaJuego", "Opcio&nes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VentanaJuego: public Ui_VentanaJuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAJUEGO_H
