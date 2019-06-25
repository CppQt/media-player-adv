#include "mymediaplayer.h"

#include <QDebug>

MyMediaPlayer::MyMediaPlayer(QObject* parent, QMediaPlayer::Flags flags) :
    QMediaPlayer(parent, flags)
{

}

QAbstractVideoSurface* MyMediaPlayer::getVideoSurface() const
{
    return m_videoSurface;
}

void MyMediaPlayer::setVideoSurface(QAbstractVideoSurface* videoSurface)
{
    qDebug() << "Changing surface";
    m_videoSurface = videoSurface;
    setVideoOutput(m_videoSurface);
}
