#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_animating(false),
    m_update_pending(false),
    m_context(NULL),
    m_show_full_screen(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(640, 480);
}
void MainWindow::render()
{

}
void MainWindow::initialize()
{

}
void MainWindow::resizeGL(int w, int h)
{
    if(h == 0)
    {
        h = 1;
    }
    if(m_context)
    {
       glViewport(0, 0, w, h);
    }
    m_projection.setToIdentity();
    m_projection.perspective(45, (float)w / (float)h, 1, 1000);
    m_modelView.setToIdentity();
}
void MainWindow::setAnimating(bool animating)
{
    m_animating = animating;
    if(animating)
    {
        renderLater();
    }

}
void MainWindow::renderLater()
{
    if(!m_update_pending)
    {
        m_update_pending = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
    }
}

void MainWindow::renderNow()
{
    if(!isExposed())
    {
            return;
    }
    bool needsInitialize = false;
    if(!m_context)
    {
        m_context = new QOpenGLContext(this);
        m_context->setFormat(requestedFormat());
        m_context->create();
        needsInitialize = true;
    }

    m_context->makeCurrent(this);
    if(needsInitialize)
    {
       initializeOpenGLFunctions();
       initialize();
       const qreal retinaScale = devicePixelRatio();
       resizeGL(width()* retinaScale, height() * retinaScale);

       render();
       m_context->swapBuffers(this);

       if(m_animating)
       {
           renderLater();
       }
    }
}
bool MainWindow::Event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::UpdateRequest:
        m_update_pending = false;
        renderNow();
        return true;
        break;
    default:
        return QMainWindow::event(event);
        break;
    }
}

void MainWindow::exposeEvent(QExposeEvent *event)
{
    if(isExposed())
    {
        renderNow();
    }

    QMainWindow::exposeEvent(event);//??
}
void MainWindow::resizeEvent(QResizeEvent *event)
{
    int w = event->size().width();
    int h = event->size().height();
    const qreal retinaScale = devicePixelRatio();
    resizeGL(w*retinaScale, h *retinaScale);
    renderNow();
    QMainWindow::resizeEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_F1:
    {
        m_show_full_screen = !m_show_full_screen;
        if(m_show_full_screen)
        {
           showFullScreen();
        }
        else
        {
            showNormal();
        }
        break;
    }
    case Qt::Key_Escape:
    {
        qApp->quit();
        break;
    }
    default:
        break;
    }
    QMainWindow::keyPressEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}
