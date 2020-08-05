/********************************************************************************
** Form generated from reading UI file 'ventanaseleccionjuego.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANASELECCIONJUEGO_H
#define UI_VENTANASELECCIONJUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaSeleccionJuego
{
public:
    QAction *actionSobrePersonajes;
    QWidget *centralwidget;
    QPushButton *reiniciarJuego;
    QPushButton *retomarJuego;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaSeleccionJuego)
    {
        if (VentanaSeleccionJuego->objectName().isEmpty())
            VentanaSeleccionJuego->setObjectName(QStringLiteral("VentanaSeleccionJuego"));
        VentanaSeleccionJuego->resize(700, 500);
        VentanaSeleccionJuego->setMinimumSize(QSize(700, 500));
        VentanaSeleccionJuego->setMaximumSize(QSize(700, 500));
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
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
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
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
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
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
        VentanaSeleccionJuego->setPalette(palette);
        actionSobrePersonajes = new QAction(VentanaSeleccionJuego);
        actionSobrePersonajes->setObjectName(QStringLiteral("actionSobrePersonajes"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/iconos/icon_info_personaje.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSobrePersonajes->setIcon(icon);
        centralwidget = new QWidget(VentanaSeleccionJuego);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        reiniciarJuego = new QPushButton(centralwidget);
        reiniciarJuego->setObjectName(QStringLiteral("reiniciarJuego"));
        reiniciarJuego->setGeometry(QRect(140, 360, 188, 41));
        reiniciarJuego->setMinimumSize(QSize(188, 41));
        reiniciarJuego->setMaximumSize(QSize(188, 41));
        reiniciarJuego->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: white;\n"
"	border-width: 3px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}"));
        retomarJuego = new QPushButton(centralwidget);
        retomarJuego->setObjectName(QStringLiteral("retomarJuego"));
        retomarJuego->setGeometry(QRect(370, 360, 188, 41));
        retomarJuego->setMinimumSize(QSize(188, 41));
        retomarJuego->setMaximumSize(QSize(188, 41));
        retomarJuego->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: white;\n"
"	border-width: 3px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}"));
        VentanaSeleccionJuego->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaSeleccionJuego);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 22));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName(QStringLiteral("menuOpciones"));
        VentanaSeleccionJuego->setMenuBar(menubar);
        statusbar = new QStatusBar(VentanaSeleccionJuego);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        VentanaSeleccionJuego->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionSobrePersonajes);

        retranslateUi(VentanaSeleccionJuego);

        QMetaObject::connectSlotsByName(VentanaSeleccionJuego);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaSeleccionJuego)
    {
        VentanaSeleccionJuego->setWindowTitle(QApplication::translate("VentanaSeleccionJuego", "MainWindow", Q_NULLPTR));
        actionSobrePersonajes->setText(QApplication::translate("VentanaSeleccionJuego", "Sobre personajes", Q_NULLPTR));
        reiniciarJuego->setText(QApplication::translate("VentanaSeleccionJuego", "Reiniciar", Q_NULLPTR));
        retomarJuego->setText(QApplication::translate("VentanaSeleccionJuego", "Retomar juego", Q_NULLPTR));
        menuOpciones->setTitle(QApplication::translate("VentanaSeleccionJuego", "Opciones", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VentanaSeleccionJuego: public Ui_VentanaSeleccionJuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANASELECCIONJUEGO_H
