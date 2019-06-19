/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2010  Pablo Alvarado
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file   mainwindow.cpp
 *         Implements the equalizer H(w) computation
 * \author Pablo Alvarado
 * \date   2010.12.12
 *
 * $Id: equalizer.cpp $
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jack.h"
#include <string>
#include <math.h>
#include <queue>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <stdio.h>

#undef _DSP_DEBUG
#define _DSP_DEBUG

#ifdef _DSP_DEBUG
#define _debug(x) std::cerr << x
#include <iostream>
#else
#define _debug(x)
#endif

using namespace std;

/**
 * Precision used by trimming
 */
const float MainWindow::Epsilon = 0.001;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    verbose_(false),
    dspChanged_(true)
{
    ui->setupUi(this);
    /*
     * Set up a timer 4 times in a second to check if the user
     * changed the equalizer values, and if so, then create a new
     * filter response
     */
    dtmf = DtmfGenerator();
    dtmf.initTones();
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(update()));
    timer_->start(250);
    dsp_ = new dspSystem;
	dsp_->setSampleRate(44100);
    dsp_->setBufferSize(3528);
    jack::init(dsp_);

    // parse some command line arguments
    QStringList argv(QCoreApplication::arguments());

    QStringList::const_iterator it(argv.begin());
    while(it!=argv.end()) {
      if ((*it)=="-v" || (*it)=="--verbose") {
        verbose_=true;
      } else if ((*it).indexOf(".wav",0,Qt::CaseInsensitive)>0) {
        //ui->fileEdit->setText(*it);
        std::string tmp(qPrintable(*it));
        jack::playAlso(tmp.c_str());
      }
      ++it;
    }

}


MainWindow::~MainWindow()
{
    jack::close();
    delete timer_;
    delete ui;
    delete dsp_;
}

void MainWindow::pushNumber(int value)
{
    QVariant qv(value);
	if (value < 10){
        ui->phoneNumber->setText(ui->phoneNumber->text() + qv.toString());
		this->dtmfGenerator(value);
	}
    else{
        QString toAdd = "";
        switch (value) {
        /*
        case 10:
            toAdd = "A";
            break;
        case 11:
            toAdd = "B";
            break;
        case 12:
            toAdd = "C";
            break;
        case 13:
            toAdd = "D";ui->phoneNumber->setText(ui->phoneNumber->text() + toAdd);
            break;
        */
        case 14:
            toAdd = "*";
            break;
        case 15:
            toAdd = "#";
            break;
        default:
            break;
        }

        ui->phoneNumber->setText(ui->phoneNumber->text() + toAdd);
    }
}



void MainWindow::updateVolume()
{
    if (!dspChanged_){
        dspChanged_=true;
    }
	dsp_->updateVolume(this->volume);
}

void MainWindow::dtmfGenerator(int value)
{
	/*
	float * mytone = new float[8000];
	for(int x = 0; x < 8000; x++)mytone[x] = sin(697.0f*float(x)/8000.0f);
	dsp_->process(mytone,NULL);
	*/

}

void MainWindow::addNumber(char number){
   // printf("%c", number);
    if(callingNumber.size()==10){
        callingNumber.pop();
    }
    callingNumber.push(number);
    return;
}

void MainWindow::addNumberList(QString number){
   // printf("%c", number);
    if(list.size()==10){
        list.pop_back();
    }
    list.push_back(number);
    return;
}

void playtone(string name){
    QString s = QString::fromLocal8Bit(name.c_str());
    //printf(s.toStdString().c_str());
    printf("\n");
    QByteArray ba = s.toLocal8Bit();
    const char *c_str2 = ba.data();
    jack::play(c_str2);
}

void MainWindow::update() {
    QMainWindow::update();
    if(dspChanged_){
        _debug("Updating" << std::endl);

        dspChanged_=false;
    }
    
}


void MainWindow::on_volumeSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolume(value);
    ;
}


void MainWindow::on_fileButton_clicked() {
    /*
  selectedFiles_ =
      QFileDialog::getOpenFileNames(this,
                                   "Select one or more audio files to open",
                                   ui->fileEdit->text(),
                                   "WAV Files (*.wav)");

  if (!selectedFiles_.empty()) {
    ui->fileEdit->setText(*selectedFiles_.begin());

    jack::stopFiles();
    QStringList::iterator it;
    for (it=selectedFiles_.begin();it!=selectedFiles_.end();++it) {
      std::string tmp(qPrintable(*it));
      jack::playAlso(tmp.c_str());
    }
  }
  */
}


void MainWindow::on_fileEdit_returnPressed() {
  jack::stopFiles();
  /*
  std::string tmp(qPrintable(ui->fileEdit->text()));
  if (!tmp.empty()) {
    jack::playAlso(tmp.c_str());
  }
  */
}

void MainWindow::on_btn0_clicked()
{
    addNumber('0');
    playtone(dtmf.getname('0'));
    this->pushNumber(0);
}

void MainWindow::on_btn1_clicked()
{
    addNumber('1');
    //dtmf.generateTone(697,1336);
    playtone(dtmf.getname('1'));
    this->pushNumber(1);
}

void MainWindow::on_btn2_clicked()
{
    addNumber('2');
    playtone(dtmf.getname('2'));
    this->pushNumber(2);
}

void MainWindow::on_btn3_clicked()
{
    addNumber('3');
    playtone(dtmf.getname('3'));
    this->pushNumber(3);
}

void MainWindow::on_btna_clicked()
{
    addNumber('a');
    //playtone(dtmf.getname('a'));
    on_pushButton_A_clicked();
    this->pushNumber(10);
}

void MainWindow::on_btn4_clicked()
{
    addNumber('4');
     playtone(dtmf.getname('4'));
    this->pushNumber(4);
}

void MainWindow::on_btn5_clicked()
{
    addNumber('5');
    playtone(dtmf.getname('5'));
    this->pushNumber(5);
}

void MainWindow::on_btn6_clicked()
{
    addNumber('6');
    playtone(dtmf.getname('6'));
    this->pushNumber(6);
}

void MainWindow::on_btnb_clicked()
{

    playtone("number.wav");
}

void MainWindow::on_btn7_clicked()
{
    addNumber('7');
    playtone(dtmf.getname('7'));
    this->pushNumber(7);
}

void MainWindow::on_btn8_clicked()
{
    addNumber('8');
   playtone(dtmf.getname('8'));
    this->pushNumber(8);
}

void MainWindow::on_btn9_clicked()
{
    addNumber('9');
   playtone(dtmf.getname('9'));
    this->pushNumber(9);
}

void MainWindow::on_btnc_clicked()
{
    //addNumber('c');
    playtone(dtmf.getname('c'));
    //this->pushNumber(12);
    if (volume < 50)volume += 5;
    this->updateVolume();
}

void MainWindow::on_btnasterisk_clicked()
{
    //addNumber('*');
    playtone(dtmf.getname('*'));
    //dtmf.generateTone(941,1209);
    //playtone();
    //this->pushNumber(14);
}

void MainWindow::on_btnhash_clicked()
{
    //addNumber('#');

    //playtone(dtmf.getname('#'));

    //this->pushNumber(15);
    on_pushButton_4_clicked();
	//_debug("dspSystem::samplingRate" << std::endl);

}

void MainWindow::on_btnd_clicked()
{
    //addNumber('d');
    playtone(dtmf.getname('d'));
    //dtmf.generateTone(941,1336);
    //this->pushNumber(13);
    if (volume > 0)volume -= 5;
    this->updateVolume();
}


void MainWindow::on_verticalSlider_valueChanged(int value)
{
	dsp_->updateSentivity(value);
}


void MainWindow::on_pushButton_A_clicked()
{
    char array[5];
    array[0] = '*';
    array[1] = '9';
    array[2] = '1';
    array[3] = '1';
    array[4] = '#';
    // generate number
    dtmf.generateNumber(array);
    addNumberList(ui->callingNumber->text());
    playtone("number.wav");
    filterList();
}


void MainWindow::on_pushButton_4_clicked()
{
    if(callingNumber.size()!=8){
        return;
    }
    char array[10];
    array[0] = '*';
    ui->callingNumber->setText("");
    for(int i =1; i<9; i++){
        //char temp = callingNumber.front();
        array[i] = callingNumber.front();
        callingNumber.pop();
        ui->callingNumber->setText(ui->callingNumber->text() + array[i]);
    }
    array[9] = '#';

    // generate number
    dtmf.generateNumber(array);
    addNumberList(ui->callingNumber->text());
    playtone("number.wav");
    filterList();
}

void MainWindow::filterList(){
    int len = list.size();
    printf("numberlist size%d",len);
    ui->comboBox->clear();
    for(int i = 0; i<len; i++){
         ui->comboBox->addItem(list[i]);
    }



}
void MainWindow::on_pushButton_3_clicked()
{
    callingNumber = {};
    ui->phoneNumber->setText("");
}
