#include <QApplication>
#include <QMessageBox>
#include <QScreen>
#include <QDebug>
#include <ctime>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    QScreen* screen = QGuiApplication::primaryScreen();

    QMessageBox msgBox;
    msgBox.setWindowTitle("Social survey!");
    msgBox.setText("R u sigma?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setIcon(QMessageBox::Question);

    int msgAns = QMessageBox::Yes;

    srand(time(0));

    msgAns = msgBox.exec();
    msgBox.setText("Think again! R u sigma?");

    while(msgAns != QMessageBox::No) {

        msgAns = msgBox.exec();
        msgBox.move(msgBox.x() + rand() % 600 - 300, msgBox.y() + rand() % 600 - 300);

        if(msgBox.x() > screen->geometry().width() - 75 || msgBox.y() > screen->geometry().height() - 75 || msgBox.x() < 75 || msgBox.y() < 75)
            msgBox.move(screen->geometry().width() / 2, screen->geometry().height() / 2);

    }
}


