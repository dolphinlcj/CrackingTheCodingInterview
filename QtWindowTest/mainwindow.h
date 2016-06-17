#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLFunctions>
#include <QEvent>
#include <QCoreApplication>
#include <QResizeEvent>
#include <QKeyEvent>
#include <QMatrix4x4>

#include <GL/glu.h>
#include <GL/glut.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setAnimating(bool animating);
public slots:
    void renderLater();
    void renderNow();
protected:
    bool event(QEvent *event);

    void exposeEvent(QExposeEvent *event);

    void resizeEvent(QResizeEvent *event);

    void keyPressEvent(QKeyEvent *event);

    virtual void render();
    virtual void initialize();
    virtual void resizeGL(int w, int h);

    QMatrix4x4 m_projection;
    QMatrix4x4 m_modelView;

private:
    bool m_animating;
    bool m_update_pending;
    QOpenGLContext *m_context;
    bool m_show_full_screen;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
