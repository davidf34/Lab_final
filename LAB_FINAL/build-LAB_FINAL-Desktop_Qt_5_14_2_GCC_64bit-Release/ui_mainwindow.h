/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *velocidad;
    QLabel *carnet;
    QLabel *frecuencia;
    QLabel *voltaje;
    QLabel *temperatura;
    QLabel *tiempo;
    QTextBrowser *salidavel;
    QTextBrowser *salidafrec;
    QTextBrowser *salidavol;
    QTextBrowser *salidatemp;
    QTextBrowser *salidatime;
    QLabel *labelEstado1;
    QLineEdit *entrada;
    QPushButton *SEND;
    QPushButton *actualiza;
    QTableWidget *tableWidget;
    QLabel *labelEstado2;
    QLabel *labelEstado3;
    QLabel *labelEstado4;
    QLabel *LabelError;
    QLabel *label;
    QLabel *label_2;
    QLabel *mensajeestado;
    QLabel *proceso_de_comunicacion;
    QTextBrowser *estado;
    QTextBrowser *carnet_2;
    QLabel *estado_comunicacion;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(744, 496);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(52, 101, 164);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        velocidad = new QLabel(centralwidget);
        velocidad->setObjectName(QString::fromUtf8("velocidad"));
        velocidad->setGeometry(QRect(290, 140, 121, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        velocidad->setFont(font);
        velocidad->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        carnet = new QLabel(centralwidget);
        carnet->setObjectName(QString::fromUtf8("carnet"));
        carnet->setGeometry(QRect(40, 70, 301, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        carnet->setFont(font1);
        carnet->setStyleSheet(QString::fromUtf8("background-color:rgb(211, 215, 207);"));
        frecuencia = new QLabel(centralwidget);
        frecuencia->setObjectName(QString::fromUtf8("frecuencia"));
        frecuencia->setGeometry(QRect(290, 170, 121, 20));
        frecuencia->setFont(font);
        frecuencia->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        voltaje = new QLabel(centralwidget);
        voltaje->setObjectName(QString::fromUtf8("voltaje"));
        voltaje->setGeometry(QRect(290, 210, 91, 20));
        voltaje->setFont(font);
        voltaje->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        temperatura = new QLabel(centralwidget);
        temperatura->setObjectName(QString::fromUtf8("temperatura"));
        temperatura->setGeometry(QRect(290, 250, 131, 16));
        temperatura->setFont(font);
        temperatura->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        tiempo = new QLabel(centralwidget);
        tiempo->setObjectName(QString::fromUtf8("tiempo"));
        tiempo->setGeometry(QRect(40, 230, 81, 16));
        tiempo->setFont(font);
        tiempo->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        salidavel = new QTextBrowser(centralwidget);
        salidavel->setObjectName(QString::fromUtf8("salidavel"));
        salidavel->setGeometry(QRect(420, 130, 151, 31));
        salidavel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        salidafrec = new QTextBrowser(centralwidget);
        salidafrec->setObjectName(QString::fromUtf8("salidafrec"));
        salidafrec->setGeometry(QRect(420, 170, 151, 31));
        salidafrec->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        salidavol = new QTextBrowser(centralwidget);
        salidavol->setObjectName(QString::fromUtf8("salidavol"));
        salidavol->setGeometry(QRect(420, 210, 151, 31));
        salidavol->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        salidatemp = new QTextBrowser(centralwidget);
        salidatemp->setObjectName(QString::fromUtf8("salidatemp"));
        salidatemp->setGeometry(QRect(420, 250, 151, 31));
        salidatemp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        salidatime = new QTextBrowser(centralwidget);
        salidatime->setObjectName(QString::fromUtf8("salidatime"));
        salidatime->setGeometry(QRect(40, 250, 121, 41));
        salidatime->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelEstado1 = new QLabel(centralwidget);
        labelEstado1->setObjectName(QString::fromUtf8("labelEstado1"));
        labelEstado1->setGeometry(QRect(590, 130, 101, 16));
        labelEstado1->setStyleSheet(QString::fromUtf8("background-color: rrgb(211, 215, 207);"));
        entrada = new QLineEdit(centralwidget);
        entrada->setObjectName(QString::fromUtf8("entrada"));
        entrada->setGeometry(QRect(40, 90, 125, 23));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setBold(true);
        font2.setWeight(75);
        entrada->setFont(font2);
        entrada->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        SEND = new QPushButton(centralwidget);
        SEND->setObjectName(QString::fromUtf8("SEND"));
        SEND->setGeometry(QRect(40, 120, 191, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        SEND->setFont(font3);
        SEND->setStyleSheet(QString::fromUtf8("color: rgb(239, 41, 41);\n"
"background-color: rgb(114, 159, 207);"));
        actualiza = new QPushButton(centralwidget);
        actualiza->setObjectName(QString::fromUtf8("actualiza"));
        actualiza->setGeometry(QRect(40, 170, 231, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        actualiza->setFont(font4);
        actualiza->setStyleSheet(QString::fromUtf8("color: rgb(239, 41, 41);\n"
"background-color: rgb(114, 159, 207);"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font5.setPointSize(13);
        font5.setBold(true);
        font5.setItalic(true);
        font5.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font5);
        __qtablewidgetitem->setBackground(QColor(115, 210, 22));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font5);
        __qtablewidgetitem1->setBackground(QColor(115, 210, 22));
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font5);
        __qtablewidgetitem2->setBackground(QColor(211, 215, 207));
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font5);
        __qtablewidgetitem3->setBackground(QColor(211, 215, 207));
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font2);
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 310, 471, 161));
        labelEstado2 = new QLabel(centralwidget);
        labelEstado2->setObjectName(QString::fromUtf8("labelEstado2"));
        labelEstado2->setGeometry(QRect(590, 250, 111, 16));
        labelEstado2->setStyleSheet(QString::fromUtf8("background-color: rrgb(211, 215, 207);"));
        labelEstado3 = new QLabel(centralwidget);
        labelEstado3->setObjectName(QString::fromUtf8("labelEstado3"));
        labelEstado3->setGeometry(QRect(590, 210, 111, 16));
        labelEstado3->setStyleSheet(QString::fromUtf8("background-color: rrgb(211, 215, 207);"));
        labelEstado4 = new QLabel(centralwidget);
        labelEstado4->setObjectName(QString::fromUtf8("labelEstado4"));
        labelEstado4->setGeometry(QRect(590, 170, 111, 16));
        labelEstado4->setStyleSheet(QString::fromUtf8("background-color: rrgb(211, 215, 207);"));
        LabelError = new QLabel(centralwidget);
        LabelError->setObjectName(QString::fromUtf8("LabelError"));
        LabelError->setGeometry(QRect(440, 70, 211, 21));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setItalic(true);
        font6.setWeight(75);
        LabelError->setFont(font6);
        LabelError->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 20, 281, 41));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font7.setPointSize(19);
        font7.setBold(true);
        font7.setItalic(true);
        font7.setWeight(75);
        label->setFont(font7);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 0, 0);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 800, 600));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/full.jpg")));
        label_2->setScaledContents(true);
        mensajeestado = new QLabel(centralwidget);
        mensajeestado->setObjectName(QString::fromUtf8("mensajeestado"));
        mensajeestado->setGeometry(QRect(580, 100, 71, 21));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font8.setPointSize(15);
        font8.setBold(true);
        font8.setItalic(true);
        font8.setWeight(75);
        mensajeestado->setFont(font8);
        mensajeestado->setStyleSheet(QString::fromUtf8("background-color: rrgb(211, 215, 207);\n"
"color: rgb(239, 41, 41);"));
        proceso_de_comunicacion = new QLabel(centralwidget);
        proceso_de_comunicacion->setObjectName(QString::fromUtf8("proceso_de_comunicacion"));
        proceso_de_comunicacion->setGeometry(QRect(520, 320, 171, 31));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font9.setPointSize(13);
        font9.setBold(false);
        font9.setItalic(false);
        font9.setWeight(9);
        proceso_de_comunicacion->setFont(font9);
        proceso_de_comunicacion->setStyleSheet(QString::fromUtf8("color: rgb(239, 41, 41);\n"
"font: 75 13pt \"Ubuntu Condensed\";\n"
"\n"
"\n"
"background-color: rgb(114, 159, 207);"));
        estado = new QTextBrowser(centralwidget);
        estado->setObjectName(QString::fromUtf8("estado"));
        estado->setGeometry(QRect(520, 380, 181, 31));
        carnet_2 = new QTextBrowser(centralwidget);
        carnet_2->setObjectName(QString::fromUtf8("carnet_2"));
        carnet_2->setGeometry(QRect(520, 440, 181, 31));
        estado_comunicacion = new QLabel(centralwidget);
        estado_comunicacion->setObjectName(QString::fromUtf8("estado_comunicacion"));
        estado_comunicacion->setGeometry(QRect(520, 360, 65, 15));
        QFont font10;
        font10.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font10.setPointSize(11);
        font10.setBold(true);
        font10.setWeight(75);
        estado_comunicacion->setFont(font10);
        estado_comunicacion->setStyleSheet(QString::fromUtf8("color: rgb(239, 41, 41);\n"
"background-color: rgb(114, 159, 207);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(520, 420, 121, 16));
        label_3->setFont(font10);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(239, 41, 41);"));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        velocidad->raise();
        carnet->raise();
        frecuencia->raise();
        voltaje->raise();
        temperatura->raise();
        tiempo->raise();
        salidavel->raise();
        salidafrec->raise();
        salidavol->raise();
        salidatemp->raise();
        salidatime->raise();
        labelEstado1->raise();
        entrada->raise();
        SEND->raise();
        actualiza->raise();
        tableWidget->raise();
        labelEstado2->raise();
        labelEstado3->raise();
        labelEstado4->raise();
        LabelError->raise();
        label->raise();
        mensajeestado->raise();
        proceso_de_comunicacion->raise();
        estado->raise();
        carnet_2->raise();
        estado_comunicacion->raise();
        label_3->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        velocidad->setText(QCoreApplication::translate("MainWindow", "VELOCIDAD (RPM)", nullptr));
        carnet->setText(QCoreApplication::translate("MainWindow", "POR FAVOR INGRESE EL NUMERO DE CARNET PARA VALIDAR:", nullptr));
        frecuencia->setText(QCoreApplication::translate("MainWindow", "FRECUENCIA (Hz)", nullptr));
        voltaje->setText(QCoreApplication::translate("MainWindow", "VOLTAJE (V)", nullptr));
        temperatura->setText(QCoreApplication::translate("MainWindow", "TEMPERATURA (\302\260c)", nullptr));
        tiempo->setText(QCoreApplication::translate("MainWindow", "TIEMPO (s)", nullptr));
        salidavel->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Mono'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0.0</p></body></html>", nullptr));
        salidafrec->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Mono'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0.0</p></body></html>", nullptr));
        salidavol->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Mono'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0.0</p></body></html>", nullptr));
        salidatemp->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Mono'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0.0</p></body></html>", nullptr));
        salidatime->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Mono'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0.0</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#if QT_CONFIG(whatsthis)
        labelEstado1->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        labelEstado1->setText(QString());
        entrada->setText(QString());
        SEND->setText(QCoreApplication::translate("MainWindow", "Obtener valores", nullptr));
        actualiza->setText(QCoreApplication::translate("MainWindow", "Actualizar valor de tolerancia y referencia", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Referencia", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Tolerancia", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "M\303\255nimo", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Velocidad", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Frecuencia", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Voltaje", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Temperatura", nullptr));
        labelEstado2->setText(QString());
        labelEstado3->setText(QString());
        labelEstado4->setText(QString());
        LabelError->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "MONITOREO DE MOTOR A.C", nullptr));
        label_2->setText(QString());
        mensajeestado->setText(QCoreApplication::translate("MainWindow", "ESTADO:", nullptr));
        proceso_de_comunicacion->setText(QCoreApplication::translate("MainWindow", "Proceso de comunicaci\303\263n", nullptr));
        estado_comunicacion->setText(QCoreApplication::translate("MainWindow", "ESTADO:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Carnet ingresado:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
