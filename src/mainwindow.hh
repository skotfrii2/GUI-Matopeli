#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QTimer>
#include "gameboard.hh"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateSnake();

private slots:
    void startClicked();
    void resetClicked();
    void snakeMovement();
    void handleUpKey();
    void handleDownKey();
    void handleLeftKey();
    void handleRightKey();

private:
    Ui::MainWindow *ui;

    //Grafiikan alue, mihin käärme ja ruoka asetetaan
    QGraphicsScene* scene_;

    //Käärmeen pää
    QGraphicsRectItem* snakeRect_;

    //Ruoka, joka on ympyränmuotoinen
    QGraphicsEllipseItem* foodCircle_;

    // Hännän ja ruumiin muoto
    QGraphicsEllipseItem* snakeBodyTailShape_;

    // Satunnaisgeneraattori, jota käytetään väreihin
    QRandomGenerator randomGenerator_;


    //Logiikkapuolen pelilauta
    GameBoard *gameboard_;


    //Ajastin
    QTimer* timer_ = new QTimer();

    //Ajastin värin vaihdolle
    QTimer* colorTimer_ = new QTimer();

    //Nuolinäppäimien alustus
    QAction* left_;
    QAction* right_;
    QAction* up_;
    QAction* down_;

    // Käyttäjän leveys ja korkeussyötteet
    int borderXAxis_ = 0;
    int borderYAxis_ = 0;

    // Käyttäjän syöttämä siemenluku
    int seedValue_ = 0;

    // Käärmeen pään neliön koko
    const int SNAKE_SIZE = 16;

    // Nuolinäppäimen asettama suunta
    // jota käytetään käärmeen liikkumiseen
    std::string direction_ = "w";

    //Ajastimen nopeus, eli kuinka nopeaa
    //käärme liikkuu
    int speed_ = 200;

    // Käärmeen pään värit
    QBrush greenBrush_ = QBrush(Qt::green);
    QPen blackPen_ = QPen(Qt::black);

    // värit, jotka satunnaisgeneroituu
    int red_;
    int green_;
    int blue_;

    // Aloittaa ajastimen ja rakentaa pelilaudan
    // rakennetaan myös käärmeen pää ja ruoka
    void game_();

    //Ajastinfunktio, jossa vaihtuu värit
    void randomColorChange_();
};
#endif // MAINWINDOW_HH
