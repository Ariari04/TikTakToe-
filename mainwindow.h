#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void onButtonClickStart();
    void onButtonClick1x1();
    void onButtonClick1x2();
    void onButtonClick1x3();
    void onButtonClick2x1();
    void onButtonClick2x2();
    void onButtonClick2x3();
    void onButtonClick3x1();
    void onButtonClick3x2();
    void onButtonClick3x3();
    void check_for_winner();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
