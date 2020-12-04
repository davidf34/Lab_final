//LABORATORIO FINAL SISTEMA DE MONITOREO MOTOR A.C
//Andres Gomez cod. 2154714 David Felipe Sandoval G cod. 2142786
//version 1.0
//incluir librerias y definir tamaños
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QTextStream>
#include<QFile>
#include<QByteArray>
#include<QDebug>
#include<QThread>
#include<stdio.h>
#include<stdlib.h>
#include<cstdio>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#define MAX_FILE_SIZE 100
#define MAX_DATA_SIZE 50
#define ARGS 5
//variables globales
//tolerancias maximos y minimos
float maxveltol=0;
float maxfrectol=0 ;
float maxvoltol=0 ;
float maxtemptol=0 ;
float minveltol=0;
float minfrectol=0 ;
float minvoltol=0 ;
float mintemptol=0 ;
char vo[MAX_DATA_SIZE];//voltaje
float vo1=0;//valor numerico del voltaje
char te[MAX_DATA_SIZE];//temperatura
float te1=0;//valor numerico de la temperatura
char v[MAX_DATA_SIZE];//velocidad
float v1=0;//valor numerico de la velocidad
char f[MAX_DATA_SIZE];//frecuencia
float f1=0;//valor numerico de la frecuencia

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Visualización de Datos");


}

MainWindow::~MainWindow()
{
    delete ui;

}

//definicion de prototipos
void lee(char prueba[MAX_FILE_SIZE],int p);
void lee1(char prueba[MAX_FILE_SIZE]);


//al oprimir la tecla de enviar
void MainWindow::on_SEND_clicked()
{

    char prueba[MAX_FILE_SIZE];// buffer para la lectura del archivo
    char carnet[MAX_DATA_SIZE];// buffer para guardar el numero de carnet que se ingresa

    int i=0,j=0;
    int file_size=sizeof(prueba);
    int u=0,band=0;
    int pid;
    QString cr;
    cr=ui->entrada->text();// tomamos el carnet introducido
    std::string ca = cr.toStdString();//qstring a std strind de c++
    for (i=0;i<8;i++) { // se convierte a char para sumarlo a los argumentos que se envian al proceso de comunicación

            carnet[i]=ca[i];
        }
    char e[MAX_DATA_SIZE];//estado
    char c[MAX_DATA_SIZE];//carnet
    char ti[MAX_DATA_SIZE];//tiempo
    char captura[MAX_DATA_SIZE];// buffer para capturar el dato
    char *prog[ARGS]; // argumentos para el proceso de comunicación
    // definicion de los argumentos del proceso de comunicación
    char ruta[MAX_DATA_SIZE]={"./UDP.bin"};
    char ruta1[MAX_DATA_SIZE]={"186.155.208.171"};
    char ruta2[MAX_DATA_SIZE]={"motor1:"};
    char ruta3[MAX_DATA_SIZE]={"65000"};
    strcat(ruta2,carnet);// se concatena el carnet introducido al tercer argumento
    // se asigna cada argumento en su posición
    prog[0]=ruta;
    prog[1]=ruta1;
    prog[2]=ruta2;
    prog[3]=ruta3;
    prog[4]=NULL;
    pid=fork();
    switch(pid){
        case 0: //crea proceso hijo
            execv("/home/alse/Documents/LAB_FINAL/UDP.bin",prog);

            break;
        case -1:// error
            qDebug()<<"Error al crear el proceso"<<endl;
            break;
        default:// proceso padre
            wait(NULL);
            lee(prueba,0); // se lee el archivo correspondiente
            //Algoritmo para tomar los datos del archivo de texto
            for (i=0;i<file_size;i++) {
                if(prueba[i] == ',' || prueba[i] == '}'){// detecta una coma o una llave
             switch(band){// switch que cambia segun el numero del dato que se va a capturar
             case 0:// primer dato
                    captura[u]='\0';

                for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                    e[j]=captura[j+1];
                     }
                     u=0;// se reinicia la posición delbuffer de captura
                    band++;// aumenta el numero del dato
                     break;

             case 1:// segundo dato
                    captura[u]='\0';

                for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                    c[j]=captura[j+1];
                    }
                    u=0;// se reinicia la posición delbuffer de captura
                    band++;// aumenta el numero del dato
                     break;

             case 2://tercer dato

              captura[u]='\0';

                for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                     v[j]=captura[j+1];
                  }
                 u=0;// se reinicia la posición delbuffer de captura
                band++;// aumenta el numero del dato
                break;

             case 3:// cuarto dato

                captura[u]='\0';

                for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                    f[j]=captura[j+1];
                }
                u=0;// se reinicia la posición delbuffer de captura
                band++;// aumenta el numero del dato
                break;

             case 4://quinto dato

                captura[u]='\0';

                for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                     vo[j]=captura[j+1];
                 }
                 u=0;// se reinicia la posición delbuffer de captura
                band++;// aumenta el numero del dato
                break;

             case 5://sexto dato

                captura[u]='\0';

                for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                    te[j]=captura[j+1];
                }
                u=0;// se reinicia la posición delbuffer de captura
               band++;// aumenta el numero del dato
               break;

            default://séptimo dato

              captura[u]='\0';

              for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                    ti[j]=captura[j+1];
               }
               u=0;// se reinicia la posición delbuffer de captura
               break;

      }
     }
      captura[u]= prueba[i];//captura el dato
      u++;
    }
}
// se han capturado todos los datos


if ((ui->entrada->text()) == "2154714"  || (ui->entrada->text()) == "2142786"  ){// valida el carnet que se ingresa
    // se muestran los datos
    ui->estado->setText(e);
    ui->carnet_2->setText(c);
    ui->salidavel->setText(v);
    ui->salidafrec->setText(f);
    ui->salidavol->setText(vo);
    ui->salidatemp->setText(te);
    ui->salidatime->setText(ti);
    // se asigna la velocidad a la variable global de voltaje
    vo1=atof(vo);

    // comparación entre los datos de voltaje
    if (vo1>minvoltol && vo1<maxvoltol){// si se encuentra dentro del rango aceptable
    QPalette alerta1;
    alerta1.setColor(QPalette::Window, Qt::black);
    alerta1.setColor(QPalette::WindowText, Qt::green);
    ui->LabelError->setText(NULL);
    ui->labelEstado3->setAutoFillBackground(true);
    ui->labelEstado3->setPalette(alerta1);
    ui->labelEstado3->setText("NORMAL");
    }
    else {// si esta fuera de rango
        QPalette alerta1;
        alerta1.setColor(QPalette::Window, Qt::black);
        alerta1.setColor(QPalette::WindowText, Qt::red);

        ui->LabelError->setText(NULL);
        ui->labelEstado3->setAutoFillBackground(true);
        ui->labelEstado3->setPalette(alerta1);
        ui->labelEstado3->setText("FUERA DE RANGO");
    }

    //se asigna la variable global de temperatura
    te1=atof(te);
    // comparación entre los datos de temperatura

    if (te1>mintemptol && te1<maxtemptol){// si se encuentra dentro del rango aceptable
        QPalette alerta1;
        alerta1.setColor(QPalette::Window, Qt::black);
        alerta1.setColor(QPalette::WindowText, Qt::green);

        ui->LabelError->setText(NULL);
        ui->labelEstado2->setAutoFillBackground(true);
        ui->labelEstado2->setPalette(alerta1);
        ui->labelEstado2->setText("NORMAL");
        }
        else {// si esta fuera de rango
            QPalette alerta1;
            alerta1.setColor(QPalette::Window, Qt::black);
            alerta1.setColor(QPalette::WindowText, Qt::red);

            ui->LabelError->setText(NULL);
            ui->labelEstado2->setAutoFillBackground(true);
            ui->labelEstado2->setPalette(alerta1);
            ui->labelEstado2->setText("FUERA DE RANGO");
        }
      //se asigna la variable global de velocidad
      v1=atof(v);
      // comparación entre los datos de velocidad
        if ( v1>minveltol && v1<maxveltol){// si se encuentra dentro del rango aceptable
        QPalette alerta1;
        alerta1.setColor(QPalette::Window, Qt::black);
        alerta1.setColor(QPalette::WindowText, Qt::green);

        ui->LabelError->setText(NULL);
        ui->labelEstado1->setAutoFillBackground(true);
        ui->labelEstado1->setPalette(alerta1);
        ui->labelEstado1->setText("NORMAL");
        }
        else {// si esta fuera de rango
            QPalette alerta1;
            alerta1.setColor(QPalette::Window, Qt::black);
            alerta1.setColor(QPalette::WindowText, Qt::red);

            ui->LabelError->setText(NULL);
            ui->labelEstado1->setAutoFillBackground(true);
            ui->labelEstado1->setPalette(alerta1);
            ui->labelEstado1->setText("FUERA DE RANGO");
        }
        //se asigna la variable global de frecuencia
       f1=atof(f);
       // comparación entre los datos de frecuencia
        if (f1>minfrectol && f1<maxfrectol){// si se encuentra dentro del rango aceptable
        QPalette alerta1;
        alerta1.setColor(QPalette::Window, Qt::black);
        alerta1.setColor(QPalette::WindowText, Qt::green);

        ui->LabelError->setText(NULL);
        ui->labelEstado4->setAutoFillBackground(true);
        ui->labelEstado4->setPalette(alerta1);
        ui->labelEstado4->setText("NORMAL");
        }
        else {// si esta fuera de rango
            QPalette alerta1;
            alerta1.setColor(QPalette::Window, Qt::black);
            alerta1.setColor(QPalette::WindowText, Qt::red);

            ui->LabelError->setText(NULL);
            ui->labelEstado4->setAutoFillBackground(true);
            ui->labelEstado4->setPalette(alerta1);
            ui->labelEstado4->setText("FUERA DE RANGO");
        }



    }
    else if((ui->entrada->text()) == NULL ){// si no se coloca ningún número pero se oprime el boton

        QPalette error01;
        error01.setColor(QPalette::Window, Qt::white);
        error01.setColor(QPalette::WindowText, Qt::red);

    /*  Nombre de cada label para los colores   */

        ui->LabelError->setText(NULL);
        ui->LabelError->setAutoFillBackground(true);
        ui->LabelError->setPalette(error01);
        ui->LabelError->setText("Error, ingrese un dato válido");

    //se borra el dato si existia o si no hay se asigna espacio en blanco
    ui->salidavel->setText(" ");
    ui->salidafrec->setText(" ");
    ui->salidavol->setText(" ");
    ui->salidatemp->setText(" ");
    ui->salidatime->setText(" ");
    }
    else {// se coloca un número que no es ninguno de los carnets


           QPalette error01;
           error01.setColor(QPalette::Window, Qt::white);
           error01.setColor(QPalette::WindowText, Qt::red);

       /*  Nombre de cada label para los colores   */

           ui->LabelError->setText(NULL);
           ui->LabelError->setAutoFillBackground(true);
           ui->LabelError->setPalette(error01);
           ui->LabelError->setText("Error, ingrese el numero de carnet ");



    //se borra el dato si existia o si no hay se asigna espacio en blanco
    ui->salidavel->setText(" ");
    ui->salidafrec->setText(" ");
    ui->salidavol->setText(" ");
    ui->salidatemp->setText(" ");
    ui->salidatime->setText(" ");

    }
}
void lee(char prueba[MAX_FILE_SIZE],int p){// funcion para leer el archivo que se requiera
    FILE *file_descriptor1;

   size_t result = 0;
   long file_size = 0;
   if (p== 0){// se elige el archivo
     file_descriptor1 = fopen ("/home/alse/Documents/LAB_FINAL/comunicacion.txt","r");}
   else{
     file_descriptor1 = fopen ("/home/alse/Documents/LAB_FINAL/referencias.txt","r");
   }

   fseek (file_descriptor1, 0, SEEK_END); //busca hasta el final

   file_size = ftell(file_descriptor1); //retorna al tamaño

   rewind (file_descriptor1); //rebobina al valor inicial

   result = fread (prueba, 1 , file_size, file_descriptor1);

   if (result != file_size)
   {
       fputs("Error de escritura de buffer", stderr);

   }

   fclose(file_descriptor1);
}


void MainWindow::on_actualiza_clicked()//actualizar las referencias y tolerancias
{
    int pid=0;
    QString cr=ui->entrada->text();// tomamos el carnet introducido
    std::string ca=cr.toStdString();//qstring a std strind de c++
    int u=0,i=0,j=0,band=0;
    char captura[MAX_DATA_SIZE];
    char motor[MAX_FILE_SIZE];
    char carnet[MAX_DATA_SIZE];
    int file_size=sizeof(motor);
    for (i=0;i<8;i++) { // se convierte a char para sumarlo a los argumentos que se envian al proceso de comunicación


        carnet[i]=ca[i];
    }
    //variables a capturar
    char    e[MAX_DATA_SIZE];//estado
    char    c[MAX_DATA_SIZE];//carnet
    char    vel[MAX_DATA_SIZE];//velocidad y tolerancia, ademas sus valores numericos
    float   vel1;
    char    veltol[MAX_DATA_SIZE];
    float   veltol1;
    char    frec[MAX_DATA_SIZE];//frecuencia y tolerancia, ademas sus valores numericos
    float   frec1;
    char    frectol[MAX_DATA_SIZE];
    float   frectol1;
    char    vol[MAX_DATA_SIZE];//voltaje y tolerancia, ademas sus valores numericos
    float   vol1;
    char    voltol[MAX_DATA_SIZE];
    float   voltol1;
    char    temp[MAX_DATA_SIZE];//temperatura y tolerancia, ademas sus valores numericos
    float   temp1;
    char    temptol[MAX_DATA_SIZE];
    float   temptol1;
    char    *prog[ARGS];//argumentos
    char ruta[MAX_DATA_SIZE]={"./ip.bin"};
    char ruta1[MAX_DATA_SIZE]={"186.155.208.171"};
    char ruta2[MAX_DATA_SIZE]={"referencia_tolerancia:"};
    char ruta3[MAX_DATA_SIZE]={"65000"};
    strcat(ruta2,carnet);// se agrega el carnet a los argumentos
    //se asignan los argumentos
    prog[0]=ruta;
    prog[1]=ruta1;
    prog[2]=ruta2;
    prog[3]=ruta3;
    prog[4]=NULL;
    pid=fork();


    switch(pid){
        case 0: //crea proceso hijo
            execv("/home/alse/Documents/LAB_FINAL/ip.bin",prog);
            break;
        case -1:// error
            qDebug()<<"Error al crear el proceso"<<endl;
            break;
        default:// proceso padre
            wait(NULL);
            lee(motor,1);//lee el archivo solicitado
            //Algoritmo para tomar los datos del archivo de texto
            for (i=0;i<file_size;i++) {
             if(motor[i] == ',' || motor[i] == '}'){// detecta una coma o una llave
              switch(band){// switch que cambia segun el numero del dato que se va a capturar
              case 0:// primer dato
                  captura[u]='\0';

                  for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                   e[j]=captura[j+1];//estado
                   }
                   //captura
                   u=0;// se reinicia la posición delbuffer de captura
                   band++;// aumenta el numero del dato
                  break;

              case 1://segundo dato
                      captura[u]='\0';

                      for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                       c[j]=captura[j+1];//carnet
                       }
                       u=0;// se reinicia la posición delbuffer de captura
                       band++;// aumenta el numero del dato
                  break;

              case 2://tercer dato

                      captura[u]='\0';

                      for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                       vel[j]=captura[j+1];
                       }

                       u=0;// se reinicia la posición delbuffer de captura
                       band++;// aumenta el numero del dato
                    break;

              case 3:// cuarto dato

                      captura[u]='\0';

                      for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                       veltol[j]=captura[j+1];
                       }
                        veltol1=atof(veltol);
                        vel1=atof(vel);
                        //se asignan los valores maximo y minimo
                        maxveltol=vel1+veltol1;
                        minveltol=vel1-veltol1;

                       u=0;// se reinicia la posición delbuffer de captura
                       band++;// aumenta el numero del dato
                  break;

              case 4://quinto dato

                      captura[u]='\0';

                      for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                       frec[j]=captura[j+1];
                       }
                       u=0;// se reinicia la posición delbuffer de captura
                       band++;// aumenta el numero del dato
                  break;

              case 5://sexto dato

                      captura[u]='\0';
                      for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                       frectol[j]=captura[j+1];
                       }
                       frectol1=atof(frectol);
                       frec1=atof(frec);
                       //se asignan los valores maximo y minimo
                       maxfrectol=frec1+frectol1;
                       minfrectol=frec1-frectol1;

                       u=0;// se reinicia la posición delbuffer de captura
                       band++;// aumenta el numero del dato
                  break;
              case 6://séptimo dato

                      captura[u]='\0';

                      for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                       vol[j]=captura[j+1];
                       }
                       u=0;// se reinicia la posición delbuffer de captura
                       band++;// aumenta el numero del dato
                  break;
              case 7://octavo dato

                      captura[u]='\0';

                      for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                       voltol[j]=captura[j+1];
                       }
                       voltol1=atof(voltol);
                       vol1=atof(vol);
                       //se asignan los valores maximo y minimo
                       maxvoltol = vol1+voltol1;
                       minvoltol = vol1-voltol1;
                       u=0;// se reinicia la posición delbuffer de captura
                       band++;// aumenta el numero del dato
                  break;
              case 8://noveno dato

                      captura[u]='\0';

                      for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                       temp[j]=captura[j+1];
                       }
                       u=0;// se reinicia la posición delbuffer de captura
                       band++;// aumenta el numero del dato
                  break;
              default://décimo dato

                      captura[u]='\0';

                      for (j=0;j<u ;j++) {// guarda en la variable el dato capturado
                       temptol[j]=captura[j+1];
                       }
                      temp1 =atof(temp);
                      temptol1=atof(temptol);
                      //se asignan los valores maximo y minimo
                      maxtemptol = temp1+temptol1;
                      mintemptol = temp1-temptol1;

                       u=0;// se reinicia la posición delbuffer de captura

                  break;

              }
             }
              captura[u]= motor[i];//captura el dato
              u++;
            }
}
// se han capturado todos los datos
            if ((ui->entrada->text()) == "2154714"  || (ui->entrada->text()) == "2142786"  ){// valida el carnet que se ingresa

            ui->estado->setText(e);
            ui->carnet_2->setText(c);
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(vel));
            ui->tableWidget->setItem(1,0,new QTableWidgetItem(frec));
            ui->tableWidget->setItem(2,0,new QTableWidgetItem(vol));
            ui->tableWidget->setItem(3,0,new QTableWidgetItem(temp));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(veltol));
            ui->tableWidget->setItem(1,1,new QTableWidgetItem(frectol));
            ui->tableWidget->setItem(2,1,new QTableWidgetItem(voltol));
            ui->tableWidget->setItem(3,1,new QTableWidgetItem(temptol));


            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number (maxveltol)));
            ui->tableWidget->setItem(1,2,new QTableWidgetItem(QString::number (maxfrectol)));
            ui->tableWidget->setItem(2,2,new QTableWidgetItem(QString::number (maxvoltol)));
            ui->tableWidget->setItem(3,2,new QTableWidgetItem(QString::number (maxtemptol)));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::number (minveltol)));
            ui->tableWidget->setItem(1,3,new QTableWidgetItem(QString::number (minfrectol)));
            ui->tableWidget->setItem(2,3,new QTableWidgetItem(QString::number (minvoltol)));
            ui->tableWidget->setItem(3,3,new QTableWidgetItem(QString::number (mintemptol)));
            }
            else if((ui->entrada->text()) == NULL ){//si no se ingresa número de carnet
            //se borra el dato si existia o si no hay se asigna espacio en blanco
            ui->LabelError->setText("Error, ingrese un dato válido");
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(1,0,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(2,0,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(3,0,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(1,1,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(2,1,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(3,1,new QTableWidgetItem(" "));

            //se borra el dato si existia o si no hay se asigna espacio en blanco
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(1,2,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(2,2,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(3,2,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(1,3,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(2,3,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(3,3,new QTableWidgetItem(" "));
            }
            else {//si se ingresa un número que no corresponde a ninguno de los carnets
            //se borra el dato si existia o si no hay se asigna espacio en blanco
            ui->LabelError->setText("Error, ingrese el numero de carnet ");
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(1,0,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(2,0,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(3,0,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(1,1,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(2,1,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(3,1,new QTableWidgetItem(" "));

            //se borra el dato si existia o si no hay se asigna espacio en blanco
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(1,2,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(2,2,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(3,2,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(1,3,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(2,3,new QTableWidgetItem(" "));
            ui->tableWidget->setItem(3,3,new QTableWidgetItem(" "));

            }

}

