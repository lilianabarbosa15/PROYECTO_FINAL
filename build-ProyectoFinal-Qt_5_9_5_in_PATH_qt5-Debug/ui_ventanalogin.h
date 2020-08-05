/********************************************************************************
** Form generated from reading UI file 'ventanalogin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANALOGIN_H
#define UI_VENTANALOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaLogin
{
public:
    QAction *actionNombresValidos;
    QAction *actionClavesValidas;
    QWidget *centralwidget;
    QPushButton *nuevoUsuario;
    QPushButton *existeUsuario;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *name;
    QLineEdit *password;
    QMenuBar *menubar;
    QMenu *menuDatos_Validos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaLogin)
    {
        if (VentanaLogin->objectName().isEmpty())
            VentanaLogin->setObjectName(QStringLiteral("VentanaLogin"));
        VentanaLogin->resize(700, 500);
        VentanaLogin->setMinimumSize(QSize(700, 500));
        VentanaLogin->setMaximumSize(QSize(700, 500));
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
        //palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
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
        //palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
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
        //palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
        VentanaLogin->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral("iconW_nave.png"), QSize(), QIcon::Normal, QIcon::Off);
        VentanaLogin->setWindowIcon(icon);
        actionNombresValidos = new QAction(VentanaLogin);
        actionNombresValidos->setObjectName(QStringLiteral("actionNombresValidos"));
        actionNombresValidos->setCheckable(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/iconos/icon_ID.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNombresValidos->setIcon(icon1);
        actionClavesValidas = new QAction(VentanaLogin);
        actionClavesValidas->setObjectName(QStringLiteral("actionClavesValidas"));
        actionClavesValidas->setCheckable(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/iconos/icon_password.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClavesValidas->setIcon(icon2);
        centralwidget = new QWidget(VentanaLogin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        nuevoUsuario = new QPushButton(centralwidget);
        nuevoUsuario->setObjectName(QStringLiteral("nuevoUsuario"));
        nuevoUsuario->setGeometry(QRect(140, 360, 188, 41));
        nuevoUsuario->setMinimumSize(QSize(188, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush8(QColor(255, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush8);
        QBrush brush9(QColor(212, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        QBrush brush10(QColor(85, 0, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(113, 0, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush12(QColor(212, 127, 127, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        //palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        //palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush13(QColor(170, 0, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        //palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
        nuevoUsuario->setPalette(palette1);
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        nuevoUsuario->setFont(font);
        nuevoUsuario->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: white;\n"
"	border-width: 3px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}"));
        existeUsuario = new QPushButton(centralwidget);
        existeUsuario->setObjectName(QStringLiteral("existeUsuario"));
        existeUsuario->setGeometry(QRect(370, 360, 188, 41));
        existeUsuario->setMinimumSize(QSize(188, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        //palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        //palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        //palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
        existeUsuario->setPalette(palette2);
        existeUsuario->setFont(font);
        existeUsuario->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: white;\n"
"	border-width: 3px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 180, 101, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 230, 101, 31));
        label_2->setFont(font1);
        name = new QLineEdit(centralwidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(330, 180, 150, 30));
        password = new QLineEdit(centralwidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(330, 230, 150, 30));
        password->setEchoMode(QLineEdit::Password);
        VentanaLogin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaLogin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 22));
        menuDatos_Validos = new QMenu(menubar);
        menuDatos_Validos->setObjectName(QStringLiteral("menuDatos_Validos"));
        VentanaLogin->setMenuBar(menubar);
        statusbar = new QStatusBar(VentanaLogin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        VentanaLogin->setStatusBar(statusbar);

        menubar->addAction(menuDatos_Validos->menuAction());
        menuDatos_Validos->addAction(actionNombresValidos);
        menuDatos_Validos->addAction(actionClavesValidas);

        retranslateUi(VentanaLogin);

        QMetaObject::connectSlotsByName(VentanaLogin);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaLogin)
    {
        VentanaLogin->setWindowTitle(QApplication::translate("VentanaLogin", "MainWindow", Q_NULLPTR));
        actionNombresValidos->setText(QApplication::translate("VentanaLogin", "Nombres validos", Q_NULLPTR));
        actionClavesValidas->setText(QApplication::translate("VentanaLogin", "Claves validas", Q_NULLPTR));
        nuevoUsuario->setText(QApplication::translate("VentanaLogin", "Registrarse", Q_NULLPTR));
        existeUsuario->setText(QApplication::translate("VentanaLogin", "Ingresar", Q_NULLPTR));
        label->setText(QApplication::translate("VentanaLogin", "NOMBRE:", Q_NULLPTR));
        label_2->setText(QApplication::translate("VentanaLogin", "CLAVE:", Q_NULLPTR));
        menuDatos_Validos->setTitle(QApplication::translate("VentanaLogin", "Datos Validos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VentanaLogin: public Ui_VentanaLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANALOGIN_H
