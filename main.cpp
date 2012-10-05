#include <QtGui>
#include "mainwindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("QT OpenGL");
    window.setGeometry(100,0,window_size_x,window_size_y); // Смещение и положение окна
    window.show();
    window.setMouseTracking(true); // вызывать метод mouseMoveEvent при изменении позиции указателя, даже без клика кнопкой мыши
    window.setCursor(QCursor(Qt::BlankCursor));

    return app.exec();
}
