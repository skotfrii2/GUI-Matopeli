#include "mainwindow.hh"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Rakennetaan grafiikan alusta, mihin käärme ja ruoka tulevat
    scene_ = new QGraphicsScene(this);

    //Yhdistetään aloitus-, nollaamisnappi ja ajastin funktioihin
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetClicked);
    connect(timer_, &QTimer::timeout, this, &MainWindow::snakeMovement);
    connect(colorTimer_, &QTimer::timeout, this, &MainWindow::randomColorChange_);


    // Rakennetaan ja yhdistetään funktioihin nuolinäppäimet
    left_ = new QAction(this);
    left_->setShortcut(QKeySequence("Left"));
    this->addAction(left_);
    connect(left_,SIGNAL(triggered()),this,SLOT(handleLeftKey()));

    right_ = new QAction(this);
    right_->setShortcut(QKeySequence("Right"));
    this->addAction(right_);
    connect(right_,SIGNAL(triggered()),this,SLOT(handleRightKey()));

    up_ = new QAction(this);
    up_->setShortcut(QKeySequence("Up"));
    this->addAction(up_);
    connect(up_,SIGNAL(triggered()),this,SLOT(handleUpKey()));

    down_ = new QAction(this);
    down_->setShortcut(QKeySequence("Down"));
    this->addAction(down_);
    connect(down_,SIGNAL(triggered()),this,SLOT(handleDownKey()));
}

MainWindow::~MainWindow()
{
    delete colorTimer_;
    delete timer_;
    delete snakeRect_;
    delete foodCircle_;
    delete snakeBodyTailShape_;
    delete gameboard_;
    delete ui;
}


//Aloitusnapin toiminta,
//aloitetaan peli ja tehdään grafiikan
//geometria ja pelialue
//PARAMETERS:
//RETURN: NONE
void MainWindow::startClicked()
{
    // Kerätään pelin nopeus käyttäjän syötteestä
    speed_ = speed_ - ui->speedSpinBox->value() * 20;

    // leftMargin ja topMargin määrää geometriset koordinaatit
    // jotta grafiikkaikkuna sijoittuu oikein
    int leftMargin = 200; // x coordinate
    int topMargin = 200; // y coordinate

    // kerätään käyttäjän
    // syötetyt siemenluku, sekä ruudukon leveys ja korkeus
    seedValue_ = ui->seedSpinBox->value();

    // Kerätään käyttäjän syöttämät
    // leveys ja korkeus ruudukoita varten
    borderXAxis_ = ui->widthSpinBox->value() * 10;
    borderYAxis_ = ui->heightSpinBox->value() * 10;

    //Asetetaan graphics viewin koko, sekä "pelialue"
    ui->graphView->setGeometry(leftMargin, topMargin, borderXAxis_*16, borderYAxis_*16);
    scene_->setSceneRect(0, 0, borderXAxis_*16, borderYAxis_*16);

    // laitetaan aloitusnappi pois päältä kesken pelin
    ui->startButton->setDisabled(true);

    //kutsutaan itse peliä
    game_();

}

//Reset napin toiminta
//alustetaan timer ja scene
//PARAMETERS:
//RETURN: NONE
void MainWindow::resetClicked()
{
    // lopetetaan ajastin ja poistetaan
    // grafiikkapiirrokset
    // sekä mahdollistetaan pelin uudestaan käynnistys
    speed_ = 200;
    ui->gameOverOrWon->setText("");
    timer_->stop();
    colorTimer_->stop();
    ui->startButton->setDisabled(false);
    scene_->clear();

}

//Ajastimen metodi, jossa käydään läpi
//jatkuvalla syötteellä uusien snake osien tuloa
//Funktio myös on vastuussa liikehdennistä
//jossa vaihdetaan käärmeen suunta
//PARAMETERS:
//RETURN: NONE
void MainWindow::snakeMovement()
{

    // Jos peli on ohi, lopetetaan ajastin ja poistutaan funktiosta
    if (gameboard_->gameOver()) {
        timer_->stop();
        colorTimer_->stop();
        if (gameboard_->dead_) {
            ui->gameOverOrWon->setText("Game Over!");
        } else {
            ui->gameOverOrWon->setText("You won!");
        }
        return;
    }

    // Jatkuvasti päivitetään, jotta grafiikka
    // vastaa logiikkapuolen (gameboard.cpp)
    // pelilautaa
    updateSnake();


    // Nuolinäppäimien mukaisesti liikutetaan
    // pelilaudan käärmettä
    if (direction_ == "w") {
        gameboard_->moveSnake("w");
    } else if (direction_ == "s") {
        gameboard_->moveSnake("s");
    } else if (direction_ == "a") {
        gameboard_->moveSnake("a");
    } else if (direction_ == "d") {
        gameboard_->moveSnake("d");
    }
}

//Ylänuolinäppäimen toiminta,
//jossa vaihdetaan käärmeen suunta
//PARAMETERS:
//RETURN: NONE

void MainWindow::handleUpKey()
{
    if (not ui->startButton->isEnabled()) {
        direction_ = "w";
    }
}

//Alanuolinäppäimen toiminta,
//jossa vaihdetaan käärmeen suunta
//PARAMETERS:
//RETURN: NONE
void MainWindow::handleDownKey()
{
    if (not ui->startButton->isEnabled()) {
        direction_ = "s";
    }
}

//Vasemman nuolinäppäimen toiminta,
//jossa vaihdetaan käärmeen suunta
//PARAMETERS:
//RETURN: NONE
void MainWindow::handleLeftKey()
{
    if (not ui->startButton->isEnabled()) {
        direction_ = "a";
    }
}

//Oikean nuolinäppäimen toiminta,
//jossa vaihdetaan käärmeen suunta
//PARAMETERS:
//RETURN: NONE
void MainWindow::handleRightKey()
{
    if (not ui->startButton->isEnabled()) {
        direction_ = "d";
    }
}

// Aloittaa ajastimen ja rakentaa pelilaudan
// rakennetaan myös käärmeen pää ja ruoka
//PARAMETERS:
//RETURN: NONE
void MainWindow::game_()
{
    colorTimer_->start(1000);
    timer_->start(speed_);
    blackPen_.setWidth(2);

    // Luodaan uusi pelilauta
    gameboard_ = new GameBoard (borderXAxis_, borderYAxis_, seedValue_);

    // Luodaan ruoka, joka on ympyrän muotoinen
    foodCircle_ = new QGraphicsEllipseItem(0, 0, 16, 16);
    foodCircle_->setBrush(Qt::red);

    //Lisätään ruoka grafiikka-alueeseen
    scene_->addItem(foodCircle_);
    ui->graphView->setScene(scene_);
}

//Generoi uudet värit käärmeen osille
//tietyn väliajoin
//PARAMETERS:
//RETURN: NONE
void MainWindow::randomColorChange_()
{
    randomGenerator_ = QRandomGenerator::securelySeeded();
    red_ = randomGenerator_.bounded(256);
    green_ = randomGenerator_.bounded(256);
    blue_ = randomGenerator_.bounded(256);
}

//Päivitetään grafiikkaan käärmeen osien sijainnit
//sekä ruoan sijainti,
//toimii ajastimen metodina
//PARAMETERS:
//RETURN: NONE
void MainWindow::updateSnake()
{
    if (gameboard_->isFood) {
        foodCircle_->setX(gameboard_->food_.x_*16);
        foodCircle_->setY(gameboard_->food_.y_*16);
        gameboard_->isFood = false;
    }

    // Poistetaan nykyiset elementit, jotta ei tule duplikaatteja
    foreach (QGraphicsItem *item, scene_->items()) {
        if (item != foodCircle_) {
            scene_->removeItem(item);
        }
    }

    // Lisätään mahdolliset uudet elementit
    for (auto &snakeObject : gameboard_->snake_) {
        if (snakeObject == gameboard_->getHead()) {
            snakeRect_ = scene_->addRect(snakeObject.x_*16, snakeObject.y_*16, SNAKE_SIZE, SNAKE_SIZE, blackPen_, greenBrush_);
            // Värin asetus satunnaisgeneraattorista
            QColor color(red_, green_, blue_);

            snakeRect_->setBrush(color);
            ui->graphView->setScene(scene_);
        } else if (snakeObject == gameboard_->getTail()) {
            snakeBodyTailShape_ = scene_->addEllipse(snakeObject.x_*16, snakeObject.y_*16, SNAKE_SIZE-6, SNAKE_SIZE-6, blackPen_, greenBrush_);
            // Värin asetus satunnaisgeneraattorista
            QColor color(green_, red_, blue_);

            snakeBodyTailShape_->setBrush(color);
            ui->graphView->setScene(scene_);
        } else {
            snakeBodyTailShape_ = scene_->addEllipse(snakeObject.x_*16, snakeObject.y_*16, SNAKE_SIZE-3, SNAKE_SIZE-3, blackPen_, greenBrush_);
            // Värin asetus satunnaisgeneraattorista
            QColor color(blue_, green_, red_);

            // Set the brush of the item to the new random color
            snakeBodyTailShape_->setBrush(color);
            ui->graphView->setScene(scene_);
        }
    }
}



