#include <qmessagebox.h>
#include <qsettings.h>
#include <qfiledialog.h>

#include "mainwindowimpl.h"
#include "tcpclass.h"
#include "generic.h"
#include "terminaldialog.h"
#include "powermeterdialog.h"
#include "../../../uC/remote_commands.h"
#include "../../../uC/ext_events.h"
#include "../../../uC/front_panel/led_control.h"

//! Band changes are done manually
#define BAND_CHANGE_MODE_MANUAL		0
//! Band changes are done automatically
#define BAND_CHANGE_MODE_AUTO			1

#define BAND_UNDEFINED	0
#define BAND_160M				1
#define BAND_80M				2
#define BAND_40M				3
#define BAND_30M				4
#define BAND_20M				5
#define BAND_17M				6
#define BAND_15M				7
#define BAND_12M				8
#define BAND_10M				9
#define BAND_MAX				BAND_10M

#define PIXMAP_BLANK QCoreApplication::applicationDirPath()+"/leds/led_blank_15x15.png"
#define PIXMAP_RED_ON QCoreApplication::applicationDirPath()+"/leds/led_red_on_15x15.png"
#define PIXMAP_GREEN_ON QCoreApplication::applicationDirPath()+"/leds/led_green_on_15x15.png"
#define PIXMAP_RED_OFF QCoreApplication::applicationDirPath()+"/leds/led_red_off_15x15.png"
#define PIXMAP_GREEN_OFF QCoreApplication::applicationDirPath()+"/leds/led_green_off_15x15.png"
#define PIXMAP_YELLOW_ON QCoreApplication::applicationDirPath()+"/leds/led_yellow_on_15x15.png"
#define PIXMAP_YELLOW_OFF QCoreApplication::applicationDirPath()+"/leds/led_yellow_off_15x15.png"

QPalette antSelPal(QColor(Qt::darkGreen));
QPalette antNotSelPal(QColor(Qt::white));

QString MainWindowImpl::getBandName(int bandIndex) {
	QString bandName = "None";

	switch(bandIndex) {
		case 0: bandName="None";
			break;
		case 1: bandName = "160m";
			break;
		case 2: bandName = "80m";
			break;
		case 3: bandName = "40m";
			break;
		case 4: bandName = "30m";
			break;
		case 5: bandName = "20m";
			break;
		case 6: bandName = "17m";
			break;
		case 7: bandName = "15m";
			break;
		case 8: bandName = "12m";
			break;
		case 9: bandName = "10m";
			break;
	}

	return(bandName);
}

void MainWindowImpl::WindowRotatorsTriggered() {
	if (rotatorWindow->isVisible())
		rotatorWindow->hide();
	else
		rotatorWindow->show();
}
  
void MainWindowImpl::pushButtonTX1Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_TOGGLE_TX_ANT1);
	}
}

void MainWindowImpl::pushButtonTX2Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_TOGGLE_TX_ANT2);
	}
}

void MainWindowImpl::pushButtonTX3Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_TOGGLE_TX_ANT3);
	}
}

void MainWindowImpl::pushButtonTX4Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_TOGGLE_TX_ANT4);
	}
}

void MainWindowImpl::pushButtonRXAnt1Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT1);
	}
}

void MainWindowImpl::pushButtonRXAnt2Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT2);
	}
}

void MainWindowImpl::pushButtonRXAnt3Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT3);
	}
}

void MainWindowImpl::pushButtonRXAnt4Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT4);
	}
}

void MainWindowImpl::pushButtonRXAnt5Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT5);
	}
}

void MainWindowImpl::pushButtonRXAnt6Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT6);
	}
}

void MainWindowImpl::pushButtonRXAnt7Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT7);
	}
}

void MainWindowImpl::pushButtonRXAnt8Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT8);
	}
}

void MainWindowImpl::pushButtonRXAnt9Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT9);
	}
}

void MainWindowImpl::pushButtonRXAnt10Clicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT10);
	}
}

void MainWindowImpl::pushButtonRXAnt11Clicked() {
    if (TCPComm->isConnected()) {
        TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT11);
    }
}

void MainWindowImpl::pushButtonRXAnt12Clicked() {
    if (TCPComm->isConnected()) {
        TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_SEL_RX_ANT12);
    }
}

void MainWindowImpl::pushButtonMenuClicked() {
  if (TCPComm->isConnected()) {
      TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_TOGGLE_MENU_BUTTON);
  }
}

void MainWindowImpl::pushButtonMenuEnterClicked() {
	if (TCPComm->isConnected()) {
    TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_TOGGLE_KNOB_BUTTON);
	}
}

void MainWindowImpl::pushButtonMenuLeftClicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_TOGGLE_KNOB_ROTATE_CCW);
	}
}

void MainWindowImpl::pushButtonMenuRightClicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_TOGGLE_KNOB_ROTATE_CW);
	}
}

void MainWindowImpl::actionSettingsEditTriggered() {
	settingsDialog->show();
}

void MainWindowImpl::actionDisconnectTriggered() {
	timerPollStatus->stop();
  timerPollRXQueue->stop();
  timerActivity->stop();

  powerMeterWindow->stopTimers();
  busClient->stopProcess();

	labelLEDRemote->setPixmap(QPixmap(PIXMAP_GREEN_OFF));

	TCPComm->stopConnection();

	actionConnect->setEnabled(true);
	actionDisconnect->setEnabled(false);

  resetGUI();
}

void MainWindowImpl::actionConnectTriggered() {
	TCPComm->connect(settingsDialog->getNetworkIPAddress(),settingsDialog->getNetworkPort());

  timerPollRXQueue->setInterval(10);
  timerPollRXQueue->start();

  timerPollStatus->setInterval(10);
  timerPollStatus->start();

  if (settingsDialog->getActivityTimer()) {
    activityTimeoutCounter = 0;

    timerActivity->setInterval(1000);
    timerActivity->start();
  }

  if (comboBoxBand->currentIndex() != 0)
    rotatorWindow->loadBand(comboBoxBand->currentIndex());

  if (settingsDialog->getPowerMeterEnabled()) {
    busClient->initClient(14, settingsDialog->getPowerMeterNetworkIPAddress(),settingsDialog->getPowerMeterNetworkPort());

    powerMeterWindow->setTimers(500,200);
    powerMeterWindow->startTimers();
  }
}

void MainWindowImpl::comboBoxBandIndexChanged(int index) {
	if (index < 10) {
		if (TCPComm->isConnected()) {
			TCPComm->addTXMessage(REMOTE_COMMAND_SET_NEW_BAND,comboBoxBand->currentIndex());
		}
	}
}

void MainWindowImpl::timerPollStatusUpdate(void) {
  TCPComm->receiveMsg();

  if (TCPComm->transmitMsg()) {
    if (settingsDialog->getActivityTimer()) {
      activityTimeoutCounter = 0;
    }
  }
}

void MainWindowImpl::pushButtonRXAntClicked() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_TOGGLE_RX_ANT_MODE);
	}
}

void MainWindowImpl::pushButtonSubClicked(){
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_BUTTON_EVENT,EXT_CTRL_TOGGLE_SUBMENU_BUTTON);
	}
}

void MainWindowImpl::actionTerminalTriggered() {
	terminalWindow->show();
}

void MainWindowImpl::setLEDStatus(unsigned int led_status, unsigned char led_ptt_status) {
	if (led_ptt_status == LED_PTT_STATUS_OK) {
		labelLEDPTT->setPixmap(QPixmap(PIXMAP_BLANK));
	}
	else if (led_ptt_status == LED_PTT_STATUS_INHIBIT) {
		labelLEDPTT->setPixmap(QPixmap(PIXMAP_RED_ON));
	}
	else if (led_ptt_status == LED_PTT_STATUS_ACTIVE) {
		labelLEDPTT->setPixmap(QPixmap(PIXMAP_GREEN_ON));
	}

	if (led_status & (1<<LED_STATUS_ERROR))
		labelLEDError->setPixmap(QPixmap(PIXMAP_RED_ON));
	else
		labelLEDError->setPixmap(QPixmap(PIXMAP_RED_OFF));

	if (led_status & (1<<LED_STATUS_TX_ANT1))
		labelLEDTX1->setPixmap(QPixmap(PIXMAP_GREEN_ON));
	else
		labelLEDTX1->setPixmap(QPixmap(PIXMAP_GREEN_OFF));

	if (led_status & (1<<LED_STATUS_TX_ANT2))
		labelLEDTX2->setPixmap(QPixmap(PIXMAP_GREEN_ON));
	else
		labelLEDTX2->setPixmap(QPixmap(PIXMAP_GREEN_OFF));

	if (led_status & (1<<LED_STATUS_TX_ANT3))
		labelLEDTX3->setPixmap(QPixmap(PIXMAP_GREEN_ON));
	else
		labelLEDTX3->setPixmap(QPixmap(PIXMAP_GREEN_OFF));

	if (led_status & (1<<LED_STATUS_TX_ANT4))
		labelLEDTX4->setPixmap(QPixmap(PIXMAP_GREEN_ON));
	else
		labelLEDTX4->setPixmap(QPixmap(PIXMAP_GREEN_OFF));

	if (led_status & (1<<LED_STATUS_RX_ANT1))
		labelLEDRX1->setPixmap(QPixmap(PIXMAP_RED_ON));
	else
		labelLEDRX1->setPixmap(QPixmap(PIXMAP_RED_OFF));

	if (led_status & (1<<LED_STATUS_RX_ANT2))
		labelLEDRX2->setPixmap(QPixmap(PIXMAP_RED_ON));
	else
		labelLEDRX2->setPixmap(QPixmap(PIXMAP_RED_OFF));

	if (led_status & (1<<LED_STATUS_RX_ANT3))
		labelLEDRX3->setPixmap(QPixmap(PIXMAP_RED_ON));
	else
		labelLEDRX3->setPixmap(QPixmap(PIXMAP_RED_OFF));

	if (led_status & (1<<LED_STATUS_RX_ANT4))
		labelLEDRX4->setPixmap(QPixmap(PIXMAP_RED_ON));
	else
		labelLEDRX4->setPixmap(QPixmap(PIXMAP_RED_OFF));

	if (led_status & (1<<LED_STATUS_AUX))
		labelLEDAUX->setPixmap(QPixmap(PIXMAP_YELLOW_ON));
	else
		labelLEDAUX->setPixmap(QPixmap(PIXMAP_YELLOW_OFF));

	if (led_status & (1<<LED_STATUS_ROTATING))
		labelLEDRotating->setPixmap(QPixmap(PIXMAP_YELLOW_ON));
	else
		labelLEDRotating->setPixmap(QPixmap(PIXMAP_YELLOW_OFF));

	if (led_status & (1<<LED_STATUS_ROTATE))
		labelLEDRotate->setPixmap(QPixmap(PIXMAP_GREEN_ON));
	else
		labelLEDRotate->setPixmap(QPixmap(PIXMAP_GREEN_OFF));

	if (led_status & (1<<LED_STATUS_TXRX))
		labelLEDTXRX->setPixmap(QPixmap(PIXMAP_GREEN_ON));
	else
		labelLEDTXRX->setPixmap(QPixmap(PIXMAP_GREEN_OFF));

	if (led_status & (1<<LED_STATUS_RXANT))
		labelLEDRXMode->setPixmap(QPixmap(PIXMAP_GREEN_ON));
	else
		labelLEDRXMode->setPixmap(QPixmap(PIXMAP_GREEN_OFF));

	if (led_status & (1<<LED_STATUS_SUB))
		labelLEDSub->setPixmap(QPixmap(PIXMAP_GREEN_ON));
	else
		labelLEDSub->setPixmap(QPixmap(PIXMAP_GREEN_OFF));
}

void MainWindowImpl::timerPollRXQueueUpdate(void) {
  if (busClient->isConnected()) {
    busClient->receiveMsg();

    if (busClient->messageInRXQueue()) {
      BUS_MESSAGE message = busClient->getMessageInRXQueue();

      if (status.currentBand > 0) {
        if (message.from_addr == settingsDialog->getPowerMeterPickupAddr(comboBoxBand->currentIndex()-1)) {
          if (message.cmd == BUS_CMD_POWERMETER_STATUS) {
            mutex.lock();

            if (settingsDialog->getPowerMeterPickupType(comboBoxBand->currentIndex()) != 0) {
              powerMeterWindow->setValues((int)(settingsDialog->getPowerMeterPickupType(comboBoxBand->currentIndex()-1)-1),message.data[2] + (message.data[1]<<8),message.data[4] + (message.data[3]<<8),message.data[6] + (message.data[5]<<8));
            }
            else
              powerMeterWindow->setValues(message.data[0],message.data[2] + (message.data[1]<<8),message.data[4] + (message.data[3]<<8),message.data[6] + (message.data[5]<<8));

            mutex.unlock();
          }
        }
      }
    }
  }

  if (TCPComm->isConnected()) {
    if (TCPComm->rxQueueSize() > 0) {
      QByteArray rxMessage = TCPComm->getMessage();

      if (rxMessage.size() >= 3) {
        unsigned int len = (rxMessage.at(1) << 8) + rxMessage.at(2);
        unsigned char cmd = rxMessage.at(0);

        if (cmd == REMOTE_COMMAND_DISPLAY_DATA) {
          if ((len == 1024) && (rxMessage.size() == 1027)) {
            unsigned int i=3;

            for (unsigned int y=0;y<8;y++)
              for (unsigned int x=0;x<128;x++)
                glcd_buffer[y][x] = ~rxMessage.at(i++);

            repaint();
          }
        }
        else if (cmd == REMOTE_COMMAND_RX_ANT_INFO) {
          switch(rxMessage.at(3)) {
            case 0:
              pushButtonRXAnt1->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 1:
              pushButtonRXAnt2->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 2:
              pushButtonRXAnt3->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 3:
              pushButtonRXAnt4->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 4:
              pushButtonRXAnt5->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 5:
              pushButtonRXAnt6->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 6:
              pushButtonRXAnt7->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 7:
              pushButtonRXAnt8->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 8:
              pushButtonRXAnt9->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 9:
              pushButtonRXAnt10->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 10:
              pushButtonRXAnt11->setText(QString(rxMessage.mid(4,len-1)));
              break;
            case 11:
              pushButtonRXAnt12->setText(QString(rxMessage.mid(4,len-1)));
              break;
            default:
              break;
          }
        }
        else if (cmd == REMOTE_COMMAND_STATUS) {
          if (rxMessage.size() > 7) {
            setLEDStatus((rxMessage.at(4) << 8) | rxMessage.at(5),rxMessage.at(3));

            comboBoxBand->blockSignals(true);

            if (currBand != rxMessage.at(6)) {
              switch(rxMessage.at(6)) {
                case BAND_UNDEFINED:
                  labelBand->setText("Band: None");
                  comboBoxBand->setCurrentIndex(0);
                  rotatorWindow->loadBand(BAND_UNDEFINED);
                  break;
                case BAND_160M:
                  labelBand->setText("Band: 160m");
                  comboBoxBand->setCurrentIndex(1);
                  rotatorWindow->loadBand(BAND_160M);
                  break;
                case BAND_80M:
                  labelBand->setText("Band: 80m");
                  comboBoxBand->setCurrentIndex(2);
                  rotatorWindow->loadBand(BAND_80M);
                  break;
                case BAND_40M:
                  labelBand->setText("Band: 40m");
                  comboBoxBand->setCurrentIndex(3);
                  rotatorWindow->loadBand(BAND_40M);
                  break;
                case BAND_30M:
                  labelBand->setText("Band: 30m");
                  comboBoxBand->setCurrentIndex(4);
                  rotatorWindow->loadBand(BAND_30M);
                  break;
                case BAND_20M:
                  labelBand->setText("Band: 20m");
                  comboBoxBand->setCurrentIndex(5);
                  rotatorWindow->loadBand(BAND_20M);
                  break;
                case BAND_17M:
                  labelBand->setText("Band: 17m");
                  comboBoxBand->setCurrentIndex(6);
                  rotatorWindow->loadBand(BAND_17M);
                  break;
                case BAND_15M:
                  labelBand->setText("Band: 15m");
                  comboBoxBand->setCurrentIndex(7);
                  rotatorWindow->loadBand(BAND_15M);
                  break;
                case BAND_12M:
                  labelBand->setText("Band: 12m");
                  comboBoxBand->setCurrentIndex(8);
                  rotatorWindow->loadBand(BAND_12M);
                  break;
                case BAND_10M:
                  labelBand->setText("Band: 10m");
                  comboBoxBand->setCurrentIndex(9);
                  rotatorWindow->loadBand(BAND_10M);
                  break;
                default:
                  labelBand->setText("Band: None");
                  comboBoxBand->setCurrentIndex(0);
                  rotatorWindow->loadBand(BAND_UNDEFINED);
                  break;
              }

              currBand = rxMessage.at(6);
            }

            comboBoxBand->blockSignals(false);
          }
        }
        else if (cmd == REMOTE_COMMAND_TERMINAL_DATA) {
          terminalWindow->addNewMessage(rxMessage);
        }
        else if (cmd == REMOTE_COMMAND_CONNECTED) {
          labelLEDRemote->setPixmap(QPixmap(PIXMAP_GREEN_ON));
          actionConnect->setEnabled(false);
          actionDisconnect->setEnabled(true);
        }
        else if (cmd == REMOTE_COMMAND_ROTATOR_SET_HEADING) {
          unsigned char temp[2];
          temp[0] = rxMessage.at(4);
          temp[1] = rxMessage.at(5);
          rotatorWindow->setRotatorAngle(rxMessage.at(3),(temp[0] << 8) + temp[1]);
          rotatorWindow->setRotatorStatusText(rxMessage.at(3),rxMessage.at(6));
        }
        else if (cmd == REMOTE_COMMAND_BAND_INFO) {
          bool bUpdateBandInfo = false;

          for (unsigned char i=0;i<6;i++) {
            unsigned char temp = currBandInfoAddr[i];
            currBandInfoAddr[i] = rxMessage.at(3+i);

            if (temp != currBandInfoAddr[i])
              bUpdateBandInfo = true;
          }

          for (unsigned char i=0;i<6;i++) {
            unsigned char temp = currBandInfoBand[i];

            currBandInfoBand[i] = rxMessage.at(9+i);

            if (temp != currBandInfoBand[i])
                bUpdateBandInfo = true;
          }

          if (bUpdateBandInfo)
            updateBandInfo();
        }
      }
    }
  }
}

void MainWindowImpl::updateBandInfo() {
  for (unsigned char i=0;i<6;i++) {
    if ((settingsDialog->getBandInfoBoxAddr(0) != 0) && (settingsDialog->getBandInfoBoxAddr(0) == currBandInfoAddr[i]))
      labelBoxABand->setText(getBandName(currBandInfoBand[i]));
    else if ((settingsDialog->getBandInfoBoxAddr(1) != 0) && (settingsDialog->getBandInfoBoxAddr(1) == currBandInfoAddr[i]))
      labelBoxBBand->setText(getBandName(currBandInfoBand[i]));
    else if ((settingsDialog->getBandInfoBoxAddr(2) != 0) && (settingsDialog->getBandInfoBoxAddr(2) == currBandInfoAddr[i]))
      labelBoxCBand->setText(getBandName(currBandInfoBand[i]));
    else if ((settingsDialog->getBandInfoBoxAddr(3) != 0) && (settingsDialog->getBandInfoBoxAddr(3) == currBandInfoAddr[i]))
      labelBoxDBand->setText(getBandName(currBandInfoBand[i]));
    else if ((settingsDialog->getBandInfoBoxAddr(4) != 0) && (settingsDialog->getBandInfoBoxAddr(4) == currBandInfoAddr[i]))
      labelBoxEBand->setText(getBandName(currBandInfoBand[i]));
    else if ((settingsDialog->getBandInfoBoxAddr(5) != 0) && (settingsDialog->getBandInfoBoxAddr(5) == currBandInfoAddr[i]))
      labelBoxFBand->setText(getBandName(currBandInfoBand[i]));
  }
}

void MainWindowImpl::closeEvent ( QCloseEvent * event ) {
	event->ignore();

	settingsDialog->setPosMainWindowX(geometry().x());
	settingsDialog->setPosMainWindowY(geometry().y());
	settingsDialog->setPosKeypadWindowX(keypadWindow->geometry().x());
	settingsDialog->setPosKeypadWindowY(keypadWindow->geometry().y());
	settingsDialog->setPosRotatorWindowX(rotatorWindow->geometry().x());
	settingsDialog->setPosRotatorWindowY(rotatorWindow->geometry().y());
	settingsDialog->setPosTerminalWindowX(terminalWindow->geometry().x());
	settingsDialog->setPosTerminalWindowY(terminalWindow->geometry().y());
  settingsDialog->setPosPowerMeterWindowX(powerMeterWindow->geometry().x());
  settingsDialog->setPosPowerMeterWindowY(powerMeterWindow->geometry().y());

  settingsDialog->setPowerMeterWindowOpen(powerMeterWindow->isVisible());
	settingsDialog->setRotatorWindowOpen(rotatorWindow->isVisible());
	settingsDialog->setTerminalWindowOpen(terminalWindow->isVisible());
	settingsDialog->setKeypadWindowOpen(keypadWindow->isVisible());

	settingsDialog->saveSettings();

	TCPComm->stopConnection();

	event->accept();
};

void MainWindowImpl::actionReconnect() {
    QTimer::singleShot(0, this, SLOT(actionDisconnectTriggered()));
    QTimer::singleShot(1000, this, SLOT(actionConnectTriggered()));
}

void MainWindowImpl::actionRebootTriggered() {
	if (TCPComm->isConnected()) {
		TCPComm->addTXMessage(REMOTE_COMMAND_FORCE_RESET);

		QTimer::singleShot(1000, this, SLOT(actionDisconnectTriggered()));
		QTimer::singleShot(5000, this, SLOT(actionConnectTriggered()));
	}
}

void MainWindowImpl::updateDisplay() {

}

void MainWindowImpl::actionPowerMeterTriggered() {
  powerMeterWindow->show();
}

void MainWindowImpl::actionKeypadTriggered() {
  keypadWindow->show();
}

void MainWindowImpl::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	painter.setViewport(180,130,512,256);

	for (unsigned int y=0;y<8;y++) {
		for (unsigned int x=0;x<128;x++) {
			for (unsigned char row=0;row<8;row++){
				if ((glcd_buffer[y][x] & (1<<row)) == 0) {
					for (unsigned char x3=0;x3<3;x3++)
						for (unsigned char y3=0;y3<3;y3++)
							painter.drawPoint(3*x+x3,3*(y*8+row)+y3);
				}
			}
		}
	}
}

void MainWindowImpl::resetGUI() {
  labelLEDPTT->setPixmap(QPixmap(PIXMAP_BLANK));
  labelLEDError->setPixmap(QPixmap(PIXMAP_RED_OFF));
  labelLEDTX1->setPixmap(QPixmap(PIXMAP_GREEN_OFF));
  labelLEDTX2->setPixmap(QPixmap(PIXMAP_GREEN_OFF));
  labelLEDTX3->setPixmap(QPixmap(PIXMAP_GREEN_OFF));
  labelLEDTX4->setPixmap(QPixmap(PIXMAP_GREEN_OFF));
  labelLEDRX1->setPixmap(QPixmap(PIXMAP_RED_OFF));
  labelLEDRX2->setPixmap(QPixmap(PIXMAP_RED_OFF));
  labelLEDRX3->setPixmap(QPixmap(PIXMAP_RED_OFF));
  labelLEDRX4->setPixmap(QPixmap(PIXMAP_RED_OFF));
  labelLEDAUX->setPixmap(QPixmap(PIXMAP_YELLOW_OFF));
  labelLEDRotating->setPixmap(QPixmap(PIXMAP_YELLOW_OFF));
  labelLEDRotate->setPixmap(QPixmap(PIXMAP_GREEN_OFF));
  labelLEDTXRX->setPixmap(QPixmap(PIXMAP_GREEN_OFF));
  labelLEDRXMode->setPixmap(QPixmap(PIXMAP_GREEN_OFF));
  labelLEDSub->setPixmap(QPixmap(PIXMAP_GREEN_OFF));
  labelLEDRemote->setPixmap(QPixmap(PIXMAP_GREEN_OFF));

  for (unsigned int y=0;y<8;y++)
    for (unsigned int x=0;x<128;x++)
      glcd_buffer[y][x] = 255;

  repaint();

  rotatorWindow->loadBand(0);
}

void MainWindowImpl::timerActivityUpdate() {
  activityTimeoutCounter++;

  if (activityTimeoutCounter > settingsDialog->getActivityTimerTimeoutLimit()) {
    actionDisconnectTriggered();
    activityTimeoutCounter = 0;

    QMessageBox::warning(
      this,
      tr("Disconnected"),
      tr("You were disconnected because of inactivity")
    );
  }
}

MainWindowImpl::MainWindowImpl ( QWidget * parent, Qt::WindowFlags f ) : QMainWindow ( parent, f ) {
	setupUi(this);

  settingsDialog = new SettingsDialog(this);
  settingsDialog->hide();

  terminalWindow = new terminalDialog(this);
  terminalWindow->hide();

  if (settingsDialog->getFrameRotatorWindow())
    rotatorWindow = new RotatorDialog(this);
  else
    rotatorWindow = new RotatorDialog(this,Qt::FramelessWindowHint);

	rotatorWindow->hide();

  powerMeterWindow = new PowerMeterDialog(this);
  powerMeterWindow->hide();

  keypadWindow = new Keypad(this);
  keypadWindow->hide();

  TCPComm = new TCPClass();

  busClient = new WMVBusClient();

  keypadWindow->setCOMMPtr(TCPComm);

  terminalWindow->setCOMMPtr(TCPComm);
  rotatorWindow->setCOMMPtr(TCPComm);

  if (settingsDialog->getShowMousePointer() == false) {
    rotatorWindow->setCursor(QCursor( Qt::BlankCursor ));
  }

  timerActivity = new QTimer(this);
  connect(timerActivity, SIGNAL(timeout()), this, SLOT(timerActivityUpdate()));


	timerPollRXQueue = new QTimer(this);
	connect(timerPollRXQueue, SIGNAL(timeout()), this, SLOT(timerPollRXQueueUpdate()));

	timerPollStatus = new QTimer(this);
	connect(timerPollStatus, SIGNAL(timeout()), this, SLOT(timerPollStatusUpdate()));

	connect(actionReboot, SIGNAL(triggered()), this, SLOT(actionRebootTriggered()));
	connect(actionSettingsEdit, SIGNAL(triggered()), this, SLOT(actionSettingsEditTriggered()));
	connect(actionWindowsRotators, SIGNAL(triggered()), this, SLOT(WindowRotatorsTriggered()));
	connect(actionConnect, SIGNAL(triggered()), this, SLOT(actionConnectTriggered()));
	connect(actionDisconnect, SIGNAL(triggered()), this, SLOT(actionDisconnectTriggered()));
	connect(actionTerminal, SIGNAL(triggered()), this, SLOT(actionTerminalTriggered()));
  connect(actionKeypad, SIGNAL(triggered()), this, SLOT(actionKeypadTriggered()));
  connect(actionPowerMeter, SIGNAL(triggered()), this, SLOT(actionPowerMeterTriggered()));

	connect(comboBoxBand, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxBandIndexChanged(int)));

	connect(pushButtonTX1, SIGNAL(clicked()), this, SLOT(pushButtonTX1Clicked()));
	connect(pushButtonTX2, SIGNAL(clicked()), this, SLOT(pushButtonTX2Clicked()));
	connect(pushButtonTX3, SIGNAL(clicked()), this, SLOT(pushButtonTX3Clicked()));
	connect(pushButtonTX4, SIGNAL(clicked()), this, SLOT(pushButtonTX4Clicked()));

	connect(pushButtonRXAnt1, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt1Clicked()));
	connect(pushButtonRXAnt2, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt2Clicked()));
	connect(pushButtonRXAnt3, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt3Clicked()));
	connect(pushButtonRXAnt4, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt4Clicked()));
	connect(pushButtonRXAnt5, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt5Clicked()));
	connect(pushButtonRXAnt6, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt6Clicked()));
	connect(pushButtonRXAnt7, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt7Clicked()));
	connect(pushButtonRXAnt8, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt8Clicked()));
	connect(pushButtonRXAnt9, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt9Clicked()));
	connect(pushButtonRXAnt10, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt10Clicked()));
  connect(pushButtonRXAnt11, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt11Clicked()));
  connect(pushButtonRXAnt12, SIGNAL(clicked()), this, SLOT(pushButtonRXAnt12Clicked()));
	connect(pushButtonRXAnt, SIGNAL(clicked()), this, SLOT(pushButtonRXAntClicked()));

	connect(pushButtonMenu, SIGNAL(clicked()), this, SLOT(pushButtonMenuClicked()));
	connect(pushButtonMenuEnter, SIGNAL(clicked()), this, SLOT(pushButtonMenuEnterClicked()));
	connect(pushButtonMenuLeft, SIGNAL(clicked()), this, SLOT(pushButtonMenuLeftClicked()));
	connect(pushButtonMenuRight, SIGNAL(clicked()), this, SLOT(pushButtonMenuRightClicked()));
    connect(pushButtonSub, SIGNAL(clicked()), this, SLOT(pushButtonSubClicked()));

  //Set the default pixmaps
  resetGUI();

	currBand = BAND_UNDEFINED;

	setGeometry(QRect(settingsDialog->getPosMainWindowX(),settingsDialog->getPosMainWindowY(),this->width(),this->height()));
	keypadWindow->setGeometry(QRect(settingsDialog->getPosKeypadWindowX(),settingsDialog->getPosKeypadWindowY(),keypadWindow->width(),keypadWindow->height()));
	rotatorWindow->setGeometry(QRect(settingsDialog->getPosRotatorWindowX(),settingsDialog->getPosRotatorWindowY(),rotatorWindow->width(),rotatorWindow->height()));
	terminalWindow->setGeometry(QRect(settingsDialog->getPosTerminalWindowX(),settingsDialog->getPosTerminalWindowY(),terminalWindow->width(),terminalWindow->height()));
  powerMeterWindow->setGeometry(QRect(settingsDialog->getPosPowerMeterWindowX(),settingsDialog->getPosPowerMeterWindowY(),powerMeterWindow->width(),powerMeterWindow->height()));

	if (settingsDialog->getRotatorWindowOpen())
		rotatorWindow->show();
	else
		rotatorWindow->hide();

	if (settingsDialog->getTerminalWindowOpen())
		terminalWindow->show();
	else
		terminalWindow->hide();

  if (settingsDialog->getPowerMeterWindowOpen())
    powerMeterWindow->show();
  else
    powerMeterWindow->hide();

	if (settingsDialog->getKeypadWindowOpen())
		keypadWindow->show();
	else
		keypadWindow->hide();

  if (settingsDialog->getConnectOnStart())
    actionConnectTriggered();

  if (settingsDialog->getFrameRotatorWindowStartOnTop()) {
    rotatorWindow->show();
  }

  for (unsigned char i=0;i<6;i++) {
    if (settingsDialog->getBandInfoBoxAddr(i) != 0) {
      if (i == 0) {
        labelBoxAName->setText(settingsDialog->getBandInfoBoxName(i)+":");
        labelBoxABand->setText("Offline");
      }
      else if (i == 1) {
        labelBoxBName->setText(settingsDialog->getBandInfoBoxName(i)+":");
        labelBoxBBand->setText("Offline");
      }
      else if (i == 2) {
        labelBoxCName->setText(settingsDialog->getBandInfoBoxName(i)+":");
        labelBoxCBand->setText("Offline");
      }
      else if (i == 3) {
        labelBoxDName->setText(settingsDialog->getBandInfoBoxName(i)+":");
        labelBoxDBand->setText("Offline");
      }
      else if (i == 4) {
        labelBoxEName->setText(settingsDialog->getBandInfoBoxName(i)+":");
        labelBoxEBand->setText("Offline");
      }
      else if (i == 5) {
        labelBoxFName->setText(settingsDialog->getBandInfoBoxName(i)+":");
        labelBoxFBand->setText("Offline");
      }
    }
  }

  updateBandInfo();
}
//
